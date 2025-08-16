/*
 * http.c
 *
 * Person B's job: Handle HTTP parsing and response building.
 *
 * Big Picture:
 *   - Get the raw request text from Person A.
 *   - Parse it into meaningful parts (method, path, headers).
 *   - Decide what response to send back (200 OK, 404 Not Found, etc).
 *   - Build the proper HTTP response string (status line, headers, body).
 *   - Return that response to Person A, so it can be sent to the client.
 *
 * Key steps (to implement one by one):
 *
 * 1. Parse the Request Line
 *    - Example: "GET /index.html HTTP/1.1"
 *    - Extract:
 *        method → "GET"
 *        path   → "/index.html"
 *        version → "HTTP/1.1"
 *    - Validate:
 *        - Only support GET (and maybe HEAD).
 *        - Only allow "HTTP/1.1".
 *        - If invalid → return "400 Bad Request" or "505 HTTP Version Not Supported".
 *
 * 2. Parse the Headers
 *    - Example:
 *        Host: localhost:8080
 *        User-Agent: Firefox
 *    - Store headers in a simple structure (array/list).
 *    - Important: "Host" must exist in HTTP/1.1 → otherwise 400.
 *    - Ignore advanced headers for now (just store them).
 *
 * 3. Normalize the Path
 *    - Path comes from request line, e.g. "/index.html".
 *    - If it's "/", default to "/index.html".
 *    - Make sure the path does NOT escape the "www/" folder
 *      (reject "../etc/passwd" attacks).
 *
 * 4. Locate the File
 *    - Join "www/" with the path → check if file exists.
 *    - If file found → 200 OK.
 *    - If not → 404 Not Found.
 *
 * 5. Determine Content-Type
 *    - Based on file extension:
 *        .html → text/html
 *        .txt  → text/plain
 *        .jpg  → image/jpeg
 *        .png  → image/png
 *        .gif  → image/gif
 *    - If unknown → application/octet-stream
 *
 * 6. Build the Response
 *    - Format:
 *        HTTP/1.1 <status_code> <reason_phrase>\r\n
 *        Header-Name: value\r\n
 *        ...
 *        \r\n
 *        <body>
 *
 *    - Always include:
 *        Date, Server, Content-Length, Content-Type, Connection: close
 *
 *    - For HEAD method → send headers only (no body).
 *
 *    - For error codes (400, 404, 500) → send a simple HTML message.
 *
 * 7. Return the Response
 *    - The function should return a complete response buffer (string/bytes).
 *    - Person A will send it to the client over the socket.
 *
 *
 * Notes for Person B:
 * -------------------
 * - You are the "chef": given an order slip (raw request), prepare the meal (response).
 * - Person A doesn’t care how you cook it, only that they get a ready-to-serve response.
 * - Pay attention to exact formatting (CRLF line endings: "\r\n").
 * - Build small helper functions:
 *      parse_request_line()
 *      parse_headers()
 *      get_mime_type()
 *      build_response()
 *
 */


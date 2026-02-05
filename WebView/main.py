import webview

webview.create_window(
    'ArgenDinoWebView', 
    'https://www.google.com',
    width=800,          # Ancho fijo
    height=600,         # Alto fijo
    resizable=False,    # Bloquea el cambio de tamaño
    confirm_close=True, # Confirma antes de cerrar la ventana
)

webview.start()
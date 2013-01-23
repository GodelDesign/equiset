(function($){
  /* $ is mapped to Drupal's version of jQuery in here */

  $(function(){
    /* document is ready in here */

    $.each($('.block-titles .node'), function(i, el) {
      $(el).mouseenter(function(e) {
        $('.block-frontcontent .node')
          .stop()
          .hide()
          .eq(i)
          .fadeTo(400, 1);
      });
    });
  });

})(jQuery);

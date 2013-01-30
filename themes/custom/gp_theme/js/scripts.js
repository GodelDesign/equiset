(function($){
  /* $ is mapped to Drupal's version of jQuery in here */

  $(function(){
    /* document is ready in here */

    $.each($('.block-titles .node'), function(i, el) {
      $(el).mouseenter(function(e) {
        thisEl = $(el);
        allEl = $('.block-frontcontent .node');
        toShow = allEl.eq(i);
        thisEl
          .addClass('dark-title')
          .siblings()
          .removeClass('dark-title');
        allEl
          .stop()
          .hide();
        if (!$.browser.msie) {toShow.fadeTo(400, 1);
          console.log(toShow);
        }
        else  {toShow.show();console.log('boo');}
      });
    });
  });
})(jQuery);

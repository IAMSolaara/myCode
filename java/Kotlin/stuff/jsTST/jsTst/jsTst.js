if (typeof kotlin === 'undefined') {
  throw new Error("Error loading module 'jsTst'. Its dependency 'kotlin' was not found. Please, check whether 'kotlin' is loaded prior to 'jsTst'.");
}var jsTst = function (_, Kotlin) {
  'use strict';
  var $$importsForInline$$ = _.$$importsForInline$$ || (_.$$importsForInline$$ = {});
  var L1 = Kotlin.Long.ONE;
  var defineInlineFunction = Kotlin.defineInlineFunction;
  function factorial(n) {
    return n === 0 ? L1 : Kotlin.Long.fromInt(n).multiply(factorial(n - 1 | 0));
  }
  var forOdd = defineInlineFunction('jsTst.forOdd_364jb5$', function ($receiver, f) {
    var tmp$;
    tmp$ = $receiver.iterator();
    while (tmp$.hasNext()) {
      var element = tmp$.next();
      if (element % 2 === 1)
        f(element);
    }
  });
  _.factorial_za3lpa$ = factorial;
  $$importsForInline$$.jsTst = _;
  _.forOdd_364jb5$ = forOdd;
  Kotlin.defineModule('jsTst', _);
  return _;
}(typeof jsTst === 'undefined' ? {} : jsTst, kotlin);

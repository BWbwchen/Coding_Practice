`define sil   32'd50000000 // slience
`define c   32'd262
`define d   32'd294
`define e   32'd330
`define f   32'd349
`define g   32'd392
`define a   32'd440
`define b   32'd494

`define hc  32'd524
`define hd  32'd588
`define he  32'd660
`define hf  32'd698
`define hg  32'd784
`define ha  32'd880
`define hb  32'd988

`define gs 32'd415
`define hfs 32'd740
`define hcs 32'd554

module music_example (
	input [11:0] ibeatNum,
	input en, // 1 for canon , 0 for ballon
	output reg [31:0] toneL = `sil,
    output reg [31:0] toneR = `sil
);

    always @* begin
        if(en == 0) begin
            case(ibeatNum)
                // note start !
                12'd0:  toneR = `sil;   12'd1:  toneR = `sil;
                12'd2:  toneR = `sil;   12'd3:  toneR = `sil;
                12'd4:  toneR = `sil;   12'd5:  toneR = `sil;
                12'd6:  toneR = `sil;   12'd7:  toneR = `sil;

                // note start !
                12'd8:  toneR = `sil;   12'd9:  toneR = `sil;
                12'd10: toneR = `sil;   12'd11: toneR = `sil;
                12'd12: toneR = `sil;   12'd13: toneR = `sil;
                12'd14: toneR = `sil;   12'd15: toneR = `sil;

                // note start !
                12'd16: toneR = `sil;   12'd17: toneR = `sil;
                12'd18: toneR = `sil;   12'd19: toneR = `sil;
                12'd20: toneR = `sil;   12'd21: toneR = `sil;
                12'd22: toneR = `sil;   12'd23: toneR = `sil;

                // note start !
                12'd24: toneR = `sil;   12'd25: toneR = `sil;
                12'd26: toneR = `sil;   12'd27: toneR = `sil;
                12'd28: toneR = `sil;   12'd29: toneR = `sil;
                12'd30: toneR = `sil;   12'd31: toneR = `sil;

                // note start !
                12'd32: toneR = `sil;   12'd33: toneR = `sil;
                12'd34: toneR = `sil;   12'd35: toneR = `sil;
                12'd36: toneR = `sil;   12'd37: toneR = `sil;
                12'd38: toneR = `sil;   12'd39: toneR = `sil;

                // note start !
                12'd40: toneR = `g; 12'd41: toneR = `g;
                12'd42: toneR = `g; 12'd43: toneR = `g;
                12'd44: toneR = `g; 12'd45: toneR = `g;
                12'd46: toneR = `g; 12'd47: toneR = `g;

                // note start !
                12'd48: toneR = `hf;    12'd49: toneR = `hf;
                12'd50: toneR = `hf;    12'd51: toneR = `hf;
                12'd52: toneR = `hf;    12'd53: toneR = `hf;
                12'd54: toneR = `hf;    12'd55: toneR = `hf;

                // note start !
                12'd56: toneR = `he;    12'd57: toneR = `he;
                12'd58: toneR = `he;    12'd59: toneR = `he;
                12'd60: toneR = `he;    12'd61: toneR = `he;
                12'd62: toneR = `he;    12'd63: toneR = `he;

                // note start !
                12'd64: toneR = `he;    12'd65: toneR = `he;
                12'd66: toneR = `he;    12'd67: toneR = `he;
                12'd68: toneR = `he;    12'd69: toneR = `he;
                12'd70: toneR = `he;    12'd71: toneR = `he;

                // note start !
                12'd72: toneR = `he;    12'd73: toneR = `he;
                12'd74: toneR = `he;    12'd75: toneR = `he;
                12'd76: toneR = `he;    12'd77: toneR = `he;
                12'd78: toneR = `he;    12'd79: toneR = `he;

                // note start !
                12'd80: toneR = `hf;    12'd81: toneR = `hf;
                12'd82: toneR = `hf;    12'd83: toneR = `hf;
                12'd84: toneR = `hf;    12'd85: toneR = `hf;
                12'd86: toneR = `hf;    12'd87: toneR = `hf;

                // note start !
                12'd88: toneR = `he;    12'd89: toneR = `he;
                12'd90: toneR = `he;    12'd91: toneR = `he;
                12'd92: toneR = `he;    12'd93: toneR = `he;
                12'd94: toneR = `he;    12'd95: toneR = `he;

                // note start !
                12'd96: toneR = `he;    12'd97: toneR = `he;
                12'd98: toneR = `he;    12'd99: toneR = `he;
                12'd100:    toneR = `he;    12'd101:    toneR = `he;
                12'd102:    toneR = `he;    12'd103:    toneR = `he;

                // note start !
                12'd104:    toneR = `hd;    12'd105:    toneR = `hd;
                12'd106:    toneR = `hd;    12'd107:    toneR = `hd;
                12'd108:    toneR = `hd;    12'd109:    toneR = `hd;
                12'd110:    toneR = `hd;    12'd111:    toneR = `hd;

                // note start !
                12'd112:    toneR = `hd;    12'd113:    toneR = `hd;
                12'd114:    toneR = `hd;    12'd115:    toneR = `hd;
                12'd116:    toneR = `hd;    12'd117:    toneR = `hd;
                12'd118:    toneR = `hd;    12'd119:    toneR = `hd;

                // note start !
                12'd120:    toneR = `hc;    12'd121:    toneR = `hc;
                12'd122:    toneR = `hc;    12'd123:    toneR = `hc;
                12'd124:    toneR = `hc;    12'd125:    toneR = `hc;
                12'd126:    toneR = `hc;    12'd127:    toneR = `hc;

                // note start !
                12'd128:    toneR = `hc;    12'd129:    toneR = `hc;
                12'd130:    toneR = `hc;    12'd131:    toneR = `hc;
                12'd132:    toneR = `hc;    12'd133:    toneR = `hc;
                12'd134:    toneR = `hc;    12'd135:    toneR = `hc;

                // note start !
                12'd136:    toneR = `hc;    12'd137:    toneR = `hc;
                12'd138:    toneR = `hc;    12'd139:    toneR = `hc;
                12'd140:    toneR = `hc;    12'd141:    toneR = `hc;
                12'd142:    toneR = `hc;    12'd143:    toneR = `hc;

                // note start !
                12'd144:    toneR = `hd;    12'd145:    toneR = `hd;
                12'd146:    toneR = `hd;    12'd147:    toneR = `hd;
                12'd148:    toneR = `hd;    12'd149:    toneR = `hd;
                12'd150:    toneR = `hd;    12'd151:    toneR = `hd;

                // note start !
                12'd152:    toneR = `he;    12'd153:    toneR = `he;
                12'd154:    toneR = `he;    12'd155:    toneR = `he;
                12'd156:    toneR = `he;    12'd157:    toneR = `he;
                12'd158:    toneR = `he;    12'd159:    toneR = `he;

                // note start !
                12'd160:    toneR = `he;    12'd161:    toneR = `he;
                12'd162:    toneR = `he;    12'd163:    toneR = `he;
                12'd164:    toneR = `he;    12'd165:    toneR = `he;
                12'd166:    toneR = `he;    12'd167:    toneR = `he;

                // note start !
                12'd168:    toneR = `hc;    12'd169:    toneR = `hc;
                12'd170:    toneR = `hc;    12'd171:    toneR = `hc;
                12'd172:    toneR = `hc;    12'd173:    toneR = `hc;
                12'd174:    toneR = `hc;    12'd175:    toneR = `hc;

                // note start !
                12'd176:    toneR = `hc;    12'd177:    toneR = `hc;
                12'd178:    toneR = `hc;    12'd179:    toneR = `hc;
                12'd180:    toneR = `hc;    12'd181:    toneR = `hc;
                12'd182:    toneR = `hc;    12'd183:    toneR = `hc;

                // note start !
                12'd184:    toneR = `g; 12'd185:    toneR = `g;
                12'd186:    toneR = `g; 12'd187:    toneR = `g;
                12'd188:    toneR = `g; 12'd189:    toneR = `g;
                12'd190:    toneR = `g; 12'd191:    toneR = `g;

                // note start !
                12'd192:    toneR = `a; 12'd193:    toneR = `a;
                12'd194:    toneR = `a; 12'd195:    toneR = `a;
                12'd196:    toneR = `a; 12'd197:    toneR = `a;
                12'd198:    toneR = `a; 12'd199:    toneR = `a;

                // note start !
                12'd200:    toneR = `a; 12'd201:    toneR = `a;
                12'd202:    toneR = `a; 12'd203:    toneR = `a;
                12'd204:    toneR = `a; 12'd205:    toneR = `a;
                12'd206:    toneR = `a; 12'd207:    toneR = `a;

                // note start !
                12'd208:    toneR = `hc;    12'd209:    toneR = `hc;
                12'd210:    toneR = `hc;    12'd211:    toneR = `hc;
                12'd212:    toneR = `hc;    12'd213:    toneR = `hc;
                12'd214:    toneR = `hc;    12'd215:    toneR = `hc;

                // note start !
                12'd216:    toneR = `hg;    12'd217:    toneR = `hg;
                12'd218:    toneR = `hg;    12'd219:    toneR = `hg;
                12'd220:    toneR = `hg;    12'd221:    toneR = `hg;
                12'd222:    toneR = `hg;    12'd223:    toneR = `hg;

                // note start !
                12'd224:    toneR = `hg;    12'd225:    toneR = `hg;
                12'd226:    toneR = `hg;    12'd227:    toneR = `hg;
                12'd228:    toneR = `hg;    12'd229:    toneR = `hg;
                12'd230:    toneR = `hg;    12'd231:    toneR = `hg;

                // note start !
                12'd232:    toneR = `hc;    12'd233:    toneR = `hc;
                12'd234:    toneR = `hc;    12'd235:    toneR = `hc;
                12'd236:    toneR = `hc;    12'd237:    toneR = `hc;
                12'd238:    toneR = `hc;    12'd239:    toneR = `hc;

                // note start !
                12'd240:    toneR = `he;    12'd241:    toneR = `he;
                12'd242:    toneR = `he;    12'd243:    toneR = `he;
                12'd244:    toneR = `he;    12'd245:    toneR = `he;
                12'd246:    toneR = `he;    12'd247:    toneR = `sil;

                // note start !
                12'd248:    toneR = `he;    12'd249:    toneR = `he;
                12'd250:    toneR = `he;    12'd251:    toneR = `he;
                12'd252:    toneR = `he;    12'd253:    toneR = `he;
                12'd254:    toneR = `he;    12'd255:    toneR = `he;

                // note start !
                12'd256:    toneR = `he;    12'd257:    toneR = `he;
                12'd258:    toneR = `he;    12'd259:    toneR = `he;
                12'd260:    toneR = `he;    12'd261:    toneR = `he;
                12'd262:    toneR = `he;    12'd263:    toneR = `he;

                // note start !
                12'd264:    toneR = `he;    12'd265:    toneR = `he;
                12'd266:    toneR = `he;    12'd267:    toneR = `he;
                12'd268:    toneR = `he;    12'd269:    toneR = `he;
                12'd270:    toneR = `he;    12'd271:    toneR = `he;

                // note start !
                12'd272:    toneR = `he;    12'd273:    toneR = `he;
                12'd274:    toneR = `he;    12'd275:    toneR = `he;
                12'd276:    toneR = `he;    12'd277:    toneR = `he;
                12'd278:    toneR = `he;    12'd279:    toneR = `he;

                // note start !
                12'd280:    toneR = `he;    12'd281:    toneR = `he;
                12'd282:    toneR = `he;    12'd283:    toneR = `he;
                12'd284:    toneR = `he;    12'd285:    toneR = `he;
                12'd286:    toneR = `he;    12'd287:    toneR = `he;

                // note start !
                12'd288:    toneR = `sil;   12'd289:    toneR = `sil;
                12'd290:    toneR = `sil;   12'd291:    toneR = `sil;
                12'd292:    toneR = `sil;   12'd293:    toneR = `sil;
                12'd294:    toneR = `sil;   12'd295:    toneR = `sil;

                // note start !
                12'd296:    toneR = `g; 12'd297:    toneR = `g;
                12'd298:    toneR = `g; 12'd299:    toneR = `g;
                12'd300:    toneR = `g; 12'd301:    toneR = `g;
                12'd302:    toneR = `g; 12'd303:    toneR = `g;

                // note start !
                12'd304:    toneR = `hf;    12'd305:    toneR = `hf;
                12'd306:    toneR = `hf;    12'd307:    toneR = `hf;
                12'd308:    toneR = `hf;    12'd309:    toneR = `hf;
                12'd310:    toneR = `hf;    12'd311:    toneR = `hf;

                // note start !
                12'd312:    toneR = `he;    12'd313:    toneR = `he;
                12'd314:    toneR = `he;    12'd315:    toneR = `he;
                12'd316:    toneR = `he;    12'd317:    toneR = `he;
                12'd318:    toneR = `he;    12'd319:    toneR = `he;

                // note start !
                12'd320:    toneR = `he;    12'd321:    toneR = `he;
                12'd322:    toneR = `he;    12'd323:    toneR = `he;
                12'd324:    toneR = `he;    12'd325:    toneR = `he;
                12'd326:    toneR = `he;    12'd327:    toneR = `he;

                // note start !
                12'd328:    toneR = `he;    12'd329:    toneR = `he;
                12'd330:    toneR = `he;    12'd331:    toneR = `he;
                12'd332:    toneR = `he;    12'd333:    toneR = `he;
                12'd334:    toneR = `he;    12'd335:    toneR = `he;

                // note start !
                12'd336:    toneR = `hf;    12'd337:    toneR = `hf;
                12'd338:    toneR = `hf;    12'd339:    toneR = `hf;
                12'd340:    toneR = `hf;    12'd341:    toneR = `hf;
                12'd342:    toneR = `hf;    12'd343:    toneR = `hf;

                // note start !
                12'd344:    toneR = `he;    12'd345:    toneR = `he;
                12'd346:    toneR = `he;    12'd347:    toneR = `he;
                12'd348:    toneR = `he;    12'd349:    toneR = `he;
                12'd350:    toneR = `he;    12'd351:    toneR = `he;

                // note start !
                12'd352:    toneR = `he;    12'd353:    toneR = `he;
                12'd354:    toneR = `he;    12'd355:    toneR = `he;
                12'd356:    toneR = `he;    12'd357:    toneR = `he;
                12'd358:    toneR = `he;    12'd359:    toneR = `he;

                // note start !
                12'd360:    toneR = `hd;    12'd361:    toneR = `hd;
                12'd362:    toneR = `hd;    12'd363:    toneR = `hd;
                12'd364:    toneR = `hd;    12'd365:    toneR = `hd;
                12'd366:    toneR = `hd;    12'd367:    toneR = `hd;

                // note start !
                12'd368:    toneR = `hd;    12'd369:    toneR = `hd;
                12'd370:    toneR = `hd;    12'd371:    toneR = `hd;
                12'd372:    toneR = `hd;    12'd373:    toneR = `hd;
                12'd374:    toneR = `hd;    12'd375:    toneR = `hd;

                // note start !
                12'd376:    toneR = `hc;    12'd377:    toneR = `hc;
                12'd378:    toneR = `hc;    12'd379:    toneR = `hc;
                12'd380:    toneR = `hc;    12'd381:    toneR = `hc;
                12'd382:    toneR = `hc;    12'd383:    toneR = `hc;

                // note start !
                12'd384:    toneR = `hc;    12'd385:    toneR = `hc;
                12'd386:    toneR = `hc;    12'd387:    toneR = `hc;
                12'd388:    toneR = `hc;    12'd389:    toneR = `hc;
                12'd390:    toneR = `hc;    12'd391:    toneR = `hc;

                // note start !
                12'd392:    toneR = `hc;    12'd393:    toneR = `hc;
                12'd394:    toneR = `hc;    12'd395:    toneR = `hc;
                12'd396:    toneR = `hc;    12'd397:    toneR = `hc;
                12'd398:    toneR = `hc;    12'd399:    toneR = `hc;

                // note start !
                12'd400:    toneR = `hd;    12'd401:    toneR = `hd;
                12'd402:    toneR = `hd;    12'd403:    toneR = `hd;
                12'd404:    toneR = `hd;    12'd405:    toneR = `hd;
                12'd406:    toneR = `hd;    12'd407:    toneR = `hd;

                // note start !
                12'd408:    toneR = `he;    12'd409:    toneR = `he;
                12'd410:    toneR = `he;    12'd411:    toneR = `he;
                12'd412:    toneR = `he;    12'd413:    toneR = `he;
                12'd414:    toneR = `he;    12'd415:    toneR = `he;

                // note start !
                12'd416:    toneR = `he;    12'd417:    toneR = `he;
                12'd418:    toneR = `he;    12'd419:    toneR = `he;
                12'd420:    toneR = `he;    12'd421:    toneR = `he;
                12'd422:    toneR = `he;    12'd423:    toneR = `he;

                // note start !
                12'd424:    toneR = `ha;    12'd425:    toneR = `ha;
                12'd426:    toneR = `ha;    12'd427:    toneR = `ha;
                12'd428:    toneR = `ha;    12'd429:    toneR = `ha;
                12'd430:    toneR = `ha;    12'd431:    toneR = `ha;

                // note start !
                12'd432:    toneR = `ha;    12'd433:    toneR = `ha;
                12'd434:    toneR = `ha;    12'd435:    toneR = `ha;
                12'd436:    toneR = `ha;    12'd437:    toneR = `ha;
                12'd438:    toneR = `ha;    12'd439:    toneR = `ha;

                // note start !
                12'd440:    toneR = `ha;    12'd441:    toneR = `ha;
                12'd442:    toneR = `ha;    12'd443:    toneR = `ha;
                12'd444:    toneR = `ha;    12'd445:    toneR = `ha;
                12'd446:    toneR = `ha;    12'd447:    toneR = `ha;

                // note start !
                12'd448:    toneR = `he;    12'd449:    toneR = `he;
                12'd450:    toneR = `he;    12'd451:    toneR = `he;
                12'd452:    toneR = `he;    12'd453:    toneR = `he;
                12'd454:    toneR = `he;    12'd455:    toneR = `he;

                // note start !
                12'd456:    toneR = `he;    12'd457:    toneR = `he;
                12'd458:    toneR = `he;    12'd459:    toneR = `he;
                12'd460:    toneR = `he;    12'd461:    toneR = `he;
                12'd462:    toneR = `he;    12'd463:    toneR = `he;

                // note start !
                12'd464:    toneR = `a; 12'd465:    toneR = `a;
                12'd466:    toneR = `a; 12'd467:    toneR = `a;
                12'd468:    toneR = `a; 12'd469:    toneR = `a;
                12'd470:    toneR = `a; 12'd471:    toneR = `a;

                // note start !
                12'd472:    toneR = `hc;    12'd473:    toneR = `hc;
                12'd474:    toneR = `hc;    12'd475:    toneR = `hc;
                12'd476:    toneR = `hc;    12'd477:    toneR = `hc;
                12'd478:    toneR = `hc;    12'd479:    toneR = `hc;

                // note start !
                12'd480:    toneR = `hc;    12'd481:    toneR = `hc;
                12'd482:    toneR = `hc;    12'd483:    toneR = `hc;
                12'd484:    toneR = `hc;    12'd485:    toneR = `hc;
                12'd486:    toneR = `hc;    12'd487:    toneR = `hc;

                // note start !
                12'd488:    toneR = `hd;    12'd489:    toneR = `hd;
                12'd490:    toneR = `hd;    12'd491:    toneR = `hd;
                12'd492:    toneR = `hd;    12'd493:    toneR = `hd;
                12'd494:    toneR = `hd;    12'd495:    toneR = `hd;

                // note start !
                12'd496:    toneR = `hd;    12'd497:    toneR = `hd;
                12'd498:    toneR = `hd;    12'd499:    toneR = `hd;
                12'd500:    toneR = `hd;    12'd501:    toneR = `hd;
                12'd502:    toneR = `hd;    12'd503:    toneR = `hd;

                // note start !
                12'd504:    toneR = `hc;    12'd505:    toneR = `hc;
                12'd506:    toneR = `hc;    12'd507:    toneR = `hc;
                12'd508:    toneR = `hc;    12'd509:    toneR = `hc;
                12'd510:    toneR = `hc;    12'd511:    toneR = `hc;

                // note start !
                12'd512:    toneR = `hc;    12'd513:    toneR = `hc;
                12'd514:    toneR = `hc;    12'd515:    toneR = `hc;
                12'd516:    toneR = `hc;    12'd517:    toneR = `hc;
                12'd518:    toneR = `hc;    12'd519:    toneR = `hc;

                // note start !
                12'd520:    toneR = `hc;    12'd521:    toneR = `hc;
                12'd522:    toneR = `hc;    12'd523:    toneR = `hc;
                12'd524:    toneR = `hc;    12'd525:    toneR = `hc;
                12'd526:    toneR = `hc;    12'd527:    toneR = `hc;

                // note start !
                12'd528:    toneR = `hc;    12'd529:    toneR = `hc;
                12'd530:    toneR = `hc;    12'd531:    toneR = `hc;
                12'd532:    toneR = `hc;    12'd533:    toneR = `hc;
                12'd534:    toneR = `hc;    12'd535:    toneR = `hc;

                // note start !
                12'd536:    toneR = `hc;    12'd537:    toneR = `hc;
                12'd538:    toneR = `hc;    12'd539:    toneR = `hc;
                12'd540:    toneR = `hc;    12'd541:    toneR = `hc;
                12'd542:    toneR = `hc;    12'd543:    toneR = `hc;

                // note start !
                12'd544:    toneR = `sil;   12'd545:    toneR = `sil;
                12'd546:    toneR = `sil;   12'd547:    toneR = `sil;
                12'd548:    toneR = `sil;   12'd549:    toneR = `sil;
                12'd550:    toneR = `sil;   12'd551:    toneR = `sil;

                // note start !
                12'd552:    toneR = `sil;   12'd553:    toneR = `sil;
                12'd554:    toneR = `sil;   12'd555:    toneR = `sil;
                12'd556:    toneR = `sil;   12'd557:    toneR = `sil;
                12'd558:    toneR = `sil;   12'd559:    toneR = `sil;

                // note start !
                12'd560:    toneR = `sil;   12'd561:    toneR = `sil;
                12'd562:    toneR = `sil;   12'd563:    toneR = `sil;
                12'd564:    toneR = `sil;   12'd565:    toneR = `sil;
                12'd566:    toneR = `sil;   12'd567:    toneR = `sil;

                // note start !
                12'd568:    toneR = `sil;   12'd569:    toneR = `sil;
                12'd570:    toneR = `sil;   12'd571:    toneR = `sil;
                12'd572:    toneR = `sil;   12'd573:    toneR = `sil;
                12'd574:    toneR = `sil;   12'd575:    toneR = `sil;

                default: toneR = `sil;
            endcase
        end else begin
            case (ibeatNum)
                // note start !
                12'd0:  toneR = `ha;    12'd1:  toneR = `ha;
                12'd2:  toneR = `ha;    12'd3:  toneR = `ha;
                12'd4:  toneR = `ha;    12'd5:  toneR = `ha;
                12'd6:  toneR = `ha;    12'd7:  toneR = `ha;

                // note start !
                12'd8:  toneR = `hfs;   12'd9:  toneR = `hfs;
                12'd10: toneR = `hfs;   12'd11: toneR = `hfs;
                12'd12: toneR = `hg;   12'd13: toneR = `hg;
                12'd14: toneR = `hg;   12'd15: toneR = `hg;

                // note start !
                12'd16: toneR = `ha;    12'd17: toneR = `ha;
                12'd18: toneR = `ha;    12'd19: toneR = `ha;
                12'd20: toneR = `ha;    12'd21: toneR = `ha;
                12'd22: toneR = `ha;    12'd23: toneR = `ha;

                // note start !
                12'd24: toneR = `hfs;   12'd25: toneR = `hfs;
                12'd26: toneR = `hfs;   12'd27: toneR = `hfs;
                12'd28: toneR = `hg;   12'd29: toneR = `hg;
                12'd30: toneR = `hg;   12'd31: toneR = `hg;

                // note start !
                12'd32: toneR = `ha;    12'd33: toneR = `ha;
                12'd34: toneR = `ha;    12'd35: toneR = `ha;
                12'd36: toneR = `a;    12'd37: toneR = `a;
                12'd38: toneR = `a;    12'd39: toneR = `a;

                // note start !
                12'd40: toneR = `b; 12'd41: toneR = `b;
                12'd42: toneR = `b; 12'd43: toneR = `b;
                12'd44: toneR = `hcs; 12'd45: toneR = `hcs;
                12'd46: toneR = `hcs; 12'd47: toneR = `hcs;

                // note start !
                12'd48: toneR = `hd;    12'd49: toneR = `hd;
                12'd50: toneR = `hd;    12'd51: toneR = `hd;
                12'd52: toneR = `he;    12'd53: toneR = `he;
                12'd54: toneR = `he;    12'd55: toneR = `he;

                // note start !
                12'd56: toneR = `hfs;   12'd57: toneR = `hfs;
                12'd58: toneR = `hfs;   12'd59: toneR = `hfs;
                12'd60: toneR = `hg;   12'd61: toneR = `hg;
                12'd62: toneR = `hg;   12'd63: toneR = `hg;

                // note start !
                12'd64: toneR = `hfs;   12'd65: toneR = `hfs;
                12'd66: toneR = `hfs;   12'd67: toneR = `hfs;
                12'd68: toneR = `hfs;   12'd69: toneR = `hfs;
                12'd70: toneR = `hfs;   12'd71: toneR = `hfs;

                // note start !
                12'd72: toneR = `hd;    12'd73: toneR = `hd;
                12'd74: toneR = `hd;    12'd75: toneR = `hd;
                12'd76: toneR = `he;    12'd77: toneR = `he;
                12'd78: toneR = `he;    12'd79: toneR = `he;

                // note start !
                12'd80: toneR = `hfs;   12'd81: toneR = `hfs;
                12'd82: toneR = `hfs;   12'd83: toneR = `hfs;
                12'd84: toneR = `hfs;   12'd85: toneR = `hfs;
                12'd86: toneR = `hfs;   12'd87: toneR = `hfs;

                // note start !
                12'd88: toneR = `f; 12'd89: toneR = `f;
                12'd90: toneR = `f; 12'd91: toneR = `f;
                12'd92: toneR = `g; 12'd93: toneR = `g;
                12'd94: toneR = `g; 12'd95: toneR = `g;

                // note start !
                12'd96: toneR = `a; 12'd97: toneR = `a;
                12'd98: toneR = `a; 12'd99: toneR = `a;
                12'd100:    toneR = `b; 12'd101:    toneR = `b;
                12'd102:    toneR = `b; 12'd103:    toneR = `b;

                // note start !
                12'd104:    toneR = `a; 12'd105:    toneR = `a;
                12'd106:    toneR = `a; 12'd107:    toneR = `a;
                12'd108:    toneR = `g; 12'd109:    toneR = `g;
                12'd110:    toneR = `g; 12'd111:    toneR = `g;

                // note start !
                12'd112:    toneR = `a; 12'd113:    toneR = `a;
                12'd114:    toneR = `a; 12'd115:    toneR = `a;
                12'd116:    toneR = `f; 12'd117:    toneR = `f;
                12'd118:    toneR = `f; 12'd119:    toneR = `f;

                // note start !
                12'd120:    toneR = `g; 12'd121:    toneR = `g;
                12'd122:    toneR = `g; 12'd123:    toneR = `g;
                12'd124:    toneR = `a; 12'd125:    toneR = `a;
                12'd126:    toneR = `a; 12'd127:    toneR = `a;

                // note start !
                12'd128:    toneR = `g; 12'd129:    toneR = `g;
                12'd130:    toneR = `g; 12'd131:    toneR = `g;
                12'd132:    toneR = `g; 12'd133:    toneR = `g;
                12'd134:    toneR = `g; 12'd135:    toneR = `g;

                // note start !
                12'd136:    toneR = `b; 12'd137:    toneR = `b;
                12'd138:    toneR = `b; 12'd139:    toneR = `b;
                12'd140:    toneR = `a; 12'd141:    toneR = `a;
                12'd142:    toneR = `a; 12'd143:    toneR = `a;

                // note start !
                12'd144:    toneR = `g; 12'd145:    toneR = `g;
                12'd146:    toneR = `g; 12'd147:    toneR = `g;
                12'd148:    toneR = `g; 12'd149:    toneR = `g;
                12'd150:    toneR = `g; 12'd151:    toneR = `g;

                // note start !
                12'd152:    toneR = `f; 12'd153:    toneR = `f;
                12'd154:    toneR = `f; 12'd155:    toneR = `f;
                12'd156:    toneR = `e; 12'd157:    toneR = `e;
                12'd158:    toneR = `e; 12'd159:    toneR = `e;

                // note start !
                12'd160:    toneR = `f; 12'd161:    toneR = `f;
                12'd162:    toneR = `f; 12'd163:    toneR = `f;
                12'd164:    toneR = `e; 12'd165:    toneR = `e;
                12'd166:    toneR = `e; 12'd167:    toneR = `e;

                // note start !
                12'd168:    toneR = `d; 12'd169:    toneR = `d;
                12'd170:    toneR = `d; 12'd171:    toneR = `d;
                12'd172:    toneR = `e; 12'd173:    toneR = `e;
                12'd174:    toneR = `e; 12'd175:    toneR = `e;

                // note start !
                12'd176:    toneR = `f; 12'd177:    toneR = `f;
                12'd178:    toneR = `f; 12'd179:    toneR = `f;
                12'd180:    toneR = `g; 12'd181:    toneR = `g;
                12'd182:    toneR = `g; 12'd183:    toneR = `g;

                // note start !
                12'd184:    toneR = `a; 12'd185:    toneR = `a;
                12'd186:    toneR = `a; 12'd187:    toneR = `a;
                12'd188:    toneR = `b; 12'd189:    toneR = `b;
                12'd190:    toneR = `b; 12'd191:    toneR = `b;

                // note start !
                12'd192:    toneR = `g; 12'd193:    toneR = `g;
                12'd194:    toneR = `g; 12'd195:    toneR = `g;
                12'd196:    toneR = `g; 12'd197:    toneR = `g;
                12'd198:    toneR = `g; 12'd199:    toneR = `g;

                // note start !
                12'd200:    toneR = `b; 12'd201:    toneR = `b;
                12'd202:    toneR = `b; 12'd203:    toneR = `b;
                12'd204:    toneR = `a; 12'd205:    toneR = `a;
                12'd206:    toneR = `a; 12'd207:    toneR = `a;

                // note start !
                12'd208:    toneR = `b; 12'd209:    toneR = `b;
                12'd210:    toneR = `b; 12'd211:    toneR = `b;
                12'd212:    toneR = `b; 12'd213:    toneR = `b;
                12'd214:    toneR = `b; 12'd215:    toneR = `b;

                // note start !
                12'd216:    toneR = `hcs;    12'd217:    toneR = `hcs;
                12'd218:    toneR = `hcs;    12'd219:    toneR = `hcs;
                12'd220:    toneR = `hd;    12'd221:    toneR = `hd;
                12'd222:    toneR = `hd;    12'd223:    toneR = `hd;

                // note start !
                12'd224:    toneR = `a; 12'd225:    toneR = `a;
                12'd226:    toneR = `a; 12'd227:    toneR = `a;
                12'd228:    toneR = `b; 12'd229:    toneR = `b;
                12'd230:    toneR = `b; 12'd231:    toneR = `b;

                // note start !
                12'd232:    toneR = `hcs;    12'd233:    toneR = `hcs;
                12'd234:    toneR = `hcs;    12'd235:    toneR = `hcs;
                12'd236:    toneR = `hd;    12'd237:    toneR = `hd;
                12'd238:    toneR = `hd;    12'd239:    toneR = `hd;

                // note start !
                12'd240:    toneR = `he;    12'd241:    toneR = `he;
                12'd242:    toneR = `he;    12'd243:    toneR = `he;
                12'd244:    toneR = `hfs;    12'd245:    toneR = `hfs;
                12'd246:    toneR = `hfs;    12'd247:    toneR = `hfs;

                // note start !
                12'd248:    toneR = `hg;    12'd249:    toneR = `hg;
                12'd250:    toneR = `hg;    12'd251:    toneR = `hg;
                12'd252:    toneR = `ha;    12'd253:    toneR = `ha;
                12'd254:    toneR = `ha;    12'd255:    toneR = `ha;

                // note start !
                12'd256:    toneR = `hfs;   12'd257:    toneR = `hfs;
                12'd258:    toneR = `hfs;   12'd259:    toneR = `hfs;
                12'd260:    toneR = `hfs;   12'd261:    toneR = `hfs;
                12'd262:    toneR = `hfs;   12'd263:    toneR = `hfs;

                // note start !
                12'd264:    toneR = `hd;    12'd265:    toneR = `hd;
                12'd266:    toneR = `hd;    12'd267:    toneR = `hd;
                12'd268:    toneR = `he;    12'd269:    toneR = `he;
                12'd270:    toneR = `he;    12'd271:    toneR = `he;

                // note start !
                12'd272:    toneR = `hfs;   12'd273:    toneR = `hfs;
                12'd274:    toneR = `hfs;   12'd275:    toneR = `hfs;
                12'd276:    toneR = `hfs;   12'd277:    toneR = `hfs;
                12'd278:    toneR = `hfs;   12'd279:    toneR = `hfs;

                // note start !
                12'd280:    toneR = `he;    12'd281:    toneR = `he;
                12'd282:    toneR = `he;    12'd283:    toneR = `he;
                12'd284:    toneR = `hd;    12'd285:    toneR = `hd;
                12'd286:    toneR = `hd;    12'd287:    toneR = `hd;

                // note start !
                12'd288:    toneR = `he;    12'd289:    toneR = `he;
                12'd290:    toneR = `he;    12'd291:    toneR = `he;
                12'd292:    toneR = `hcs;    12'd293:    toneR = `hcs;
                12'd294:    toneR = `hcs;    12'd295:    toneR = `hcs;

                // note start !
                12'd296:    toneR = `hd;    12'd297:    toneR = `hd;
                12'd298:    toneR = `hd;    12'd299:    toneR = `hd;
                12'd300:    toneR = `he;    12'd301:    toneR = `he;
                12'd302:    toneR = `he;    12'd303:    toneR = `he;

                // note start !
                12'd304:    toneR = `hfs;   12'd305:    toneR = `hfs;
                12'd306:    toneR = `hfs;   12'd307:    toneR = `hfs;
                12'd308:    toneR = `he;   12'd309:    toneR = `he;
                12'd310:    toneR = `he;   12'd311:    toneR = `he;

                // note start !
                12'd312:    toneR = `hd;    12'd313:    toneR = `hd;
                12'd314:    toneR = `hd;    12'd315:    toneR = `hd;
                12'd316:    toneR = `hcs;    12'd317:    toneR = `hcs;
                12'd318:    toneR = `hcs;    12'd319:    toneR = `hcs;

                // note start !
                12'd320:    toneR = `hd;    12'd321:    toneR = `hd;
                12'd322:    toneR = `hd;    12'd323:    toneR = `hd;
                12'd324:    toneR = `hd;    12'd325:    toneR = `hd;
                12'd326:    toneR = `hd;    12'd327:    toneR = `hd;

                // note start !
                12'd328:    toneR = `b; 12'd329:    toneR = `b;
                12'd330:    toneR = `b; 12'd331:    toneR = `b;
                12'd332:    toneR = `hcs; 12'd333:    toneR = `hcs;
                12'd334:    toneR = `hcs; 12'd335:    toneR = `hcs;

                // note start !
                12'd336:    toneR = `hd;    12'd337:    toneR = `hd;
                12'd338:    toneR = `hd;    12'd339:    toneR = `hd;
                12'd340:    toneR = `hd;    12'd341:    toneR = `hd;
                12'd342:    toneR = `hd;    12'd343:    toneR = `hd;

                // note start !
                12'd344:    toneR = `d; 12'd345:    toneR = `d;
                12'd346:    toneR = `d; 12'd347:    toneR = `d;
                12'd348:    toneR = `e; 12'd349:    toneR = `e;
                12'd350:    toneR = `e; 12'd351:    toneR = `e;

                // note start !
                12'd352:    toneR = `f; 12'd353:    toneR = `f;
                12'd354:    toneR = `f; 12'd355:    toneR = `f;
                12'd356:    toneR = `g; 12'd357:    toneR = `g;
                12'd358:    toneR = `g; 12'd359:    toneR = `g;

                // note start !
                12'd360:    toneR = `f; 12'd361:    toneR = `f;
                12'd362:    toneR = `f; 12'd363:    toneR = `f;
                12'd364:    toneR = `e; 12'd365:    toneR = `e;
                12'd366:    toneR = `e; 12'd367:    toneR = `e;

                // note start !
                12'd368:    toneR = `f; 12'd369:    toneR = `f;
                12'd370:    toneR = `f; 12'd371:    toneR = `f;
                12'd372:    toneR = `hd; 12'd373:    toneR = `hd;
                12'd374:    toneR = `hd; 12'd375:    toneR = `hd;

                // note start !
                12'd376:    toneR = `hcs;    12'd377:    toneR = `hcs;
                12'd378:    toneR = `hcs;    12'd379:    toneR = `hcs;
                12'd380:    toneR = `hd;    12'd381:    toneR = `hd;
                12'd382:    toneR = `hd;    12'd383:    toneR = `hd;

                // note start !
                12'd384:    toneR = `b; 12'd385:    toneR = `b;
                12'd386:    toneR = `b; 12'd387:    toneR = `b;
                12'd388:    toneR = `b; 12'd389:    toneR = `b;
                12'd390:    toneR = `b; 12'd391:    toneR = `b;

                // note start !
                12'd392:    toneR = `hd;    12'd393:    toneR = `hd;
                12'd394:    toneR = `hd;    12'd395:    toneR = `hd;
                12'd396:    toneR = `hcs;    12'd397:    toneR = `hcs;
                12'd398:    toneR = `hcs;    12'd399:    toneR = `hcs;

                // note start !
                12'd400:    toneR = `b; 12'd401:    toneR = `b;
                12'd402:    toneR = `b; 12'd403:    toneR = `b;
                12'd404:    toneR = `b; 12'd405:    toneR = `b;
                12'd406:    toneR = `b; 12'd407:    toneR = `b;

                // note start !
                12'd408:    toneR = `a; 12'd409:    toneR = `a;
                12'd410:    toneR = `a; 12'd411:    toneR = `a;
                12'd412:    toneR = `g; 12'd413:    toneR = `g;
                12'd414:    toneR = `g; 12'd415:    toneR = `g;

                // note start !
                12'd416:    toneR = `a; 12'd417:    toneR = `a;
                12'd418:    toneR = `a; 12'd419:    toneR = `a;
                12'd420:    toneR = `g; 12'd421:    toneR = `g;
                12'd422:    toneR = `g; 12'd423:    toneR = `g;

                // note start !
                12'd424:    toneR = `f; 12'd425:    toneR = `f;
                12'd426:    toneR = `f; 12'd427:    toneR = `f;
                12'd428:    toneR = `g; 12'd429:    toneR = `g;
                12'd430:    toneR = `g; 12'd431:    toneR = `g;

                // note start !
                12'd432:    toneR = `a; 12'd433:    toneR = `a;
                12'd434:    toneR = `a; 12'd435:    toneR = `a;
                12'd436:    toneR = `b; 12'd437:    toneR = `b;
                12'd438:    toneR = `b; 12'd439:    toneR = `b;

                // note start !
                12'd440:    toneR = `hcs;    12'd441:    toneR = `hcs;
                12'd442:    toneR = `hcs;    12'd443:    toneR = `hcs;
                12'd444:    toneR = `hd;    12'd445:    toneR = `hd;
                12'd446:    toneR = `hd;    12'd447:    toneR = `hd;

                // note start !
                12'd448:    toneR = `b; 12'd449:    toneR = `b;
                12'd450:    toneR = `b; 12'd451:    toneR = `b;
                12'd452:    toneR = `b; 12'd453:    toneR = `b;
                12'd454:    toneR = `b; 12'd455:    toneR = `b;

                // note start !
                12'd456:    toneR = `hd;    12'd457:    toneR = `hd;
                12'd458:    toneR = `hd;    12'd459:    toneR = `hd;
                12'd460:    toneR = `hcs;    12'd461:    toneR = `hcs;
                12'd462:    toneR = `hcs;    12'd463:    toneR = `hcs;

                // note start !
                12'd464:    toneR = `hd;    12'd465:    toneR = `hd;
                12'd466:    toneR = `hd;    12'd467:    toneR = `hd;
                12'd468:    toneR = `hd;    12'd469:    toneR = `hd;
                12'd470:    toneR = `hd;    12'd471:    toneR = `hd;

                // note start !
                12'd472:    toneR = `hcs;    12'd473:    toneR = `hcs;
                12'd474:    toneR = `hcs;    12'd475:    toneR = `hcs;
                12'd476:    toneR = `b;    12'd477:    toneR = `b;
                12'd478:    toneR = `b;    12'd479:    toneR = `b;

                // note start !
                12'd480:    toneR = `hcs;    12'd481:    toneR = `hcs;
                12'd482:    toneR = `hcs;    12'd483:    toneR = `hcs;
                12'd484:    toneR = `hd;    12'd485:    toneR = `hd;
                12'd486:    toneR = `hd;    12'd487:    toneR = `hd;

                // note start !
                12'd488:    toneR = `he;    12'd489:    toneR = `he;
                12'd490:    toneR = `he;    12'd491:    toneR = `he;
                12'd492:    toneR = `hd;    12'd493:    toneR = `hd;
                12'd494:    toneR = `hd;    12'd495:    toneR = `hd;

                // note start !
                12'd496:    toneR = `hcs;    12'd497:    toneR = `hcs;
                12'd498:    toneR = `hcs;    12'd499:    toneR = `hcs;
                12'd500:    toneR = `hd;    12'd501:    toneR = `hd;
                12'd502:    toneR = `hd;    12'd503:    toneR = `hd;

                // note start !
                12'd504:    toneR = `b; 12'd505:    toneR = `b;
                12'd506:    toneR = `b; 12'd507:    toneR = `b;
                12'd508:    toneR = `hcs; 12'd509:    toneR = `hcs;
                12'd510:    toneR = `hcs; 12'd511:    toneR = `hcs;


                default : toneR = `sil;
            endcase
        end
    end

    always @(*) begin
        if(en==0)begin
            case(ibeatNum)
                // note start !
                12'd0:  toneL = `sil;   12'd1:  toneL = `sil;
                12'd2:  toneL = `sil;   12'd3:  toneL = `sil;
                12'd4:  toneL = `sil;   12'd5:  toneL = `sil;
                12'd6:  toneL = `sil;   12'd7:  toneL = `sil;

                // note start !
                12'd8:  toneL = `sil;   12'd9:  toneL = `sil;
                12'd10: toneL = `sil;   12'd11: toneL = `sil;
                12'd12: toneL = `sil;   12'd13: toneL = `sil;
                12'd14: toneL = `sil;   12'd15: toneL = `sil;

                // note start !
                12'd16: toneL = `sil;   12'd17: toneL = `sil;
                12'd18: toneL = `sil;   12'd19: toneL = `sil;
                12'd20: toneL = `sil;   12'd21: toneL = `sil;
                12'd22: toneL = `sil;   12'd23: toneL = `sil;

                // note start !
                12'd24: toneL = `sil;   12'd25: toneL = `sil;
                12'd26: toneL = `sil;   12'd27: toneL = `sil;
                12'd28: toneL = `sil;   12'd29: toneL = `sil;
                12'd30: toneL = `sil;   12'd31: toneL = `sil;

                // note start !
                12'd32: toneL = `sil;   12'd33: toneL = `sil;
                12'd34: toneL = `sil;   12'd35: toneL = `sil;
                12'd36: toneL = `sil;   12'd37: toneL = `sil;
                12'd38: toneL = `sil;   12'd39: toneL = `sil;

                // note start !
                12'd40: toneL = `sil;   12'd41: toneL = `sil;
                12'd42: toneL = `sil;   12'd43: toneL = `sil;
                12'd44: toneL = `sil;   12'd45: toneL = `sil;
                12'd46: toneL = `sil;   12'd47: toneL = `sil;

                // note start !
                12'd48: toneL = `sil;   12'd49: toneL = `sil;
                12'd50: toneL = `sil;   12'd51: toneL = `sil;
                12'd52: toneL = `sil;   12'd53: toneL = `sil;
                12'd54: toneL = `sil;   12'd55: toneL = `sil;

                // note start !
                12'd56: toneL = `sil;   12'd57: toneL = `sil;
                12'd58: toneL = `sil;   12'd59: toneL = `sil;
                12'd60: toneL = `sil;   12'd61: toneL = `sil;
                12'd62: toneL = `sil;   12'd63: toneL = `sil;

                // note start !
                12'd64: toneL = `c; 12'd65: toneL = `c;
                12'd66: toneL = `c; 12'd67: toneL = `c;
                12'd68: toneL = `c; 12'd69: toneL = `c;
                12'd70: toneL = `c; 12'd71: toneL = `c;

                // note start !
                12'd72: toneL = `e; 12'd73: toneL = `e;
                12'd74: toneL = `e; 12'd75: toneL = `e;
                12'd76: toneL = `e; 12'd77: toneL = `e;
                12'd78: toneL = `e; 12'd79: toneL = `e;

                // note start !
                12'd80: toneL = `g; 12'd81: toneL = `g;
                12'd82: toneL = `g; 12'd83: toneL = `g;
                12'd84: toneL = `g; 12'd85: toneL = `g;
                12'd86: toneL = `g; 12'd87: toneL = `g;

                // note start !
                12'd88: toneL = `g; 12'd89: toneL = `g;
                12'd90: toneL = `g; 12'd91: toneL = `g;
                12'd92: toneL = `g; 12'd93: toneL = `g;
                12'd94: toneL = `g; 12'd95: toneL = `g;

                // note start !
                12'd96: toneL = `e; 12'd97: toneL = `e;
                12'd98: toneL = `e; 12'd99: toneL = `e;
                12'd100:    toneL = `e; 12'd101:    toneL = `e;
                12'd102:    toneL = `e; 12'd103:    toneL = `e;

                // note start !
                12'd104:    toneL = `gs;    12'd105:    toneL = `gs;
                12'd106:    toneL = `gs;    12'd107:    toneL = `gs;
                12'd108:    toneL = `gs;    12'd109:    toneL = `gs;
                12'd110:    toneL = `gs;    12'd111:    toneL = `gs;

                // note start !
                12'd112:    toneL = `b; 12'd113:    toneL = `b;
                12'd114:    toneL = `b; 12'd115:    toneL = `b;
                12'd116:    toneL = `b; 12'd117:    toneL = `b;
                12'd118:    toneL = `b; 12'd119:    toneL = `b;

                // note start !
                12'd120:    toneL = `a; 12'd121:    toneL = `a;
                12'd122:    toneL = `a; 12'd123:    toneL = `a;
                12'd124:    toneL = `a; 12'd125:    toneL = `a;
                12'd126:    toneL = `a; 12'd127:    toneL = `a;

                // note start !
                12'd128:    toneL = `a; 12'd129:    toneL = `a;
                12'd130:    toneL = `a; 12'd131:    toneL = `a;
                12'd132:    toneL = `a; 12'd133:    toneL = `a;
                12'd134:    toneL = `a; 12'd135:    toneL = `a;

                // note start !
                12'd136:    toneL = `e; 12'd137:    toneL = `e;
                12'd138:    toneL = `e; 12'd139:    toneL = `e;
                12'd140:    toneL = `e; 12'd141:    toneL = `e;
                12'd142:    toneL = `e; 12'd143:    toneL = `e;

                // note start !
                12'd144:    toneL = `a; 12'd145:    toneL = `a;
                12'd146:    toneL = `a; 12'd147:    toneL = `a;
                12'd148:    toneL = `a; 12'd149:    toneL = `a;
                12'd150:    toneL = `a; 12'd151:    toneL = `a;

                // note start !
                12'd152:    toneL = `a; 12'd153:    toneL = `a;
                12'd154:    toneL = `a; 12'd155:    toneL = `a;
                12'd156:    toneL = `a; 12'd157:    toneL = `a;
                12'd158:    toneL = `a; 12'd159:    toneL = `a;

                // note start !
                12'd160:    toneL = `a; 12'd161:    toneL = `a;
                12'd162:    toneL = `a; 12'd163:    toneL = `a;
                12'd164:    toneL = `a; 12'd165:    toneL = `a;
                12'd166:    toneL = `a; 12'd167:    toneL = `a;

                // note start !
                12'd168:    toneL = `hc;    12'd169:    toneL = `hc;
                12'd170:    toneL = `hc;    12'd171:    toneL = `hc;
                12'd172:    toneL = `hc;    12'd173:    toneL = `hc;
                12'd174:    toneL = `hc;    12'd175:    toneL = `hc;

                // note start !
                12'd176:    toneL = `g; 12'd177:    toneL = `g;
                12'd178:    toneL = `g; 12'd179:    toneL = `g;
                12'd180:    toneL = `g; 12'd181:    toneL = `g;
                12'd182:    toneL = `g; 12'd183:    toneL = `g;

                // note start !
                12'd184:    toneL = `e; 12'd185:    toneL = `e;
                12'd186:    toneL = `e; 12'd187:    toneL = `e;
                12'd188:    toneL = `e; 12'd189:    toneL = `e;
                12'd190:    toneL = `e; 12'd191:    toneL = `e;

                // note start !
                12'd192:    toneL = `f; 12'd193:    toneL = `f;
                12'd194:    toneL = `f; 12'd195:    toneL = `f;
                12'd196:    toneL = `f; 12'd197:    toneL = `f;
                12'd198:    toneL = `f; 12'd199:    toneL = `f;

                // note start !
                12'd200:    toneL = `a; 12'd201:    toneL = `a;
                12'd202:    toneL = `a; 12'd203:    toneL = `a;
                12'd204:    toneL = `a; 12'd205:    toneL = `a;
                12'd206:    toneL = `a; 12'd207:    toneL = `a;

                // note start !
                12'd208:    toneL = `a; 12'd209:    toneL = `a;
                12'd210:    toneL = `a; 12'd211:    toneL = `a;
                12'd212:    toneL = `a; 12'd213:    toneL = `a;
                12'd214:    toneL = `a; 12'd215:    toneL = `a;

                // note start !
                12'd216:    toneL = `hc;    12'd217:    toneL = `hc;
                12'd218:    toneL = `hc;    12'd219:    toneL = `hc;
                12'd220:    toneL = `hc;    12'd221:    toneL = `hc;
                12'd222:    toneL = `hc;    12'd223:    toneL = `hc;

                // note start !
                12'd224:    toneL = `g; 12'd225:    toneL = `g;
                12'd226:    toneL = `g; 12'd227:    toneL = `g;
                12'd228:    toneL = `g; 12'd229:    toneL = `g;
                12'd230:    toneL = `g; 12'd231:    toneL = `sil;

                // note start !
                12'd232:    toneL = `g; 12'd233:    toneL = `g;
                12'd234:    toneL = `g; 12'd235:    toneL = `g;
                12'd236:    toneL = `g; 12'd237:    toneL = `g;
                12'd238:    toneL = `g; 12'd239:    toneL = `g;

                // note start !
                12'd240:    toneL = `g; 12'd241:    toneL = `g;
                12'd242:    toneL = `g; 12'd243:    toneL = `g;
                12'd244:    toneL = `g; 12'd245:    toneL = `g;
                12'd246:    toneL = `g; 12'd247:    toneL = `sil;

                // note start !
                12'd248:    toneL = `g; 12'd249:    toneL = `g;
                12'd250:    toneL = `g; 12'd251:    toneL = `g;
                12'd252:    toneL = `g; 12'd253:    toneL = `g;
                12'd254:    toneL = `g; 12'd255:    toneL = `g;

                // note start !
                12'd256:    toneL = `g; 12'd257:    toneL = `g;
                12'd258:    toneL = `g; 12'd259:    toneL = `g;
                12'd260:    toneL = `g; 12'd261:    toneL = `g;
                12'd262:    toneL = `g; 12'd263:    toneL = `sil;

                // note start !
                12'd264:    toneL = `g; 12'd265:    toneL = `g;
                12'd266:    toneL = `g; 12'd267:    toneL = `g;
                12'd268:    toneL = `g; 12'd269:    toneL = `g;
                12'd270:    toneL = `g; 12'd271:    toneL = `g;

                // note start !
                12'd272:    toneL = `e; 12'd273:    toneL = `e;
                12'd274:    toneL = `e; 12'd275:    toneL = `e;
                12'd276:    toneL = `e; 12'd277:    toneL = `e;
                12'd278:    toneL = `e; 12'd279:    toneL = `e;

                // note start !
                12'd280:    toneL = `g; 12'd281:    toneL = `g;
                12'd282:    toneL = `g; 12'd283:    toneL = `g;
                12'd284:    toneL = `g; 12'd285:    toneL = `g;
                12'd286:    toneL = `g; 12'd287:    toneL = `g;

                // note start !
                12'd288:    toneL = `b; 12'd289:    toneL = `b;
                12'd290:    toneL = `b; 12'd291:    toneL = `b;
                12'd292:    toneL = `b; 12'd293:    toneL = `b;
                12'd294:    toneL = `b; 12'd295:    toneL = `b;

                // note start !
                12'd296:    toneL = `b; 12'd297:    toneL = `b;
                12'd298:    toneL = `b; 12'd299:    toneL = `b;
                12'd300:    toneL = `b; 12'd301:    toneL = `b;
                12'd302:    toneL = `b; 12'd303:    toneL = `b;

                // note start !
                12'd304:    toneL = `b; 12'd305:    toneL = `b;
                12'd306:    toneL = `b; 12'd307:    toneL = `b;
                12'd308:    toneL = `b; 12'd309:    toneL = `b;
                12'd310:    toneL = `b; 12'd311:    toneL = `b;

                // note start !
                12'd312:    toneL = `b; 12'd313:    toneL = `b;
                12'd314:    toneL = `b; 12'd315:    toneL = `b;
                12'd316:    toneL = `b; 12'd317:    toneL = `b;
                12'd318:    toneL = `b; 12'd319:    toneL = `b;

                // note start !
                12'd320:    toneL = `c; 12'd321:    toneL = `c;
                12'd322:    toneL = `c; 12'd323:    toneL = `c;
                12'd324:    toneL = `c; 12'd325:    toneL = `c;
                12'd326:    toneL = `c; 12'd327:    toneL = `c;

                // note start !
                12'd328:    toneL = `e; 12'd329:    toneL = `e;
                12'd330:    toneL = `e; 12'd331:    toneL = `e;
                12'd332:    toneL = `e; 12'd333:    toneL = `e;
                12'd334:    toneL = `e; 12'd335:    toneL = `e;

                // note start !
                12'd336:    toneL = `g; 12'd337:    toneL = `g;
                12'd338:    toneL = `g; 12'd339:    toneL = `g;
                12'd340:    toneL = `g; 12'd341:    toneL = `g;
                12'd342:    toneL = `g; 12'd343:    toneL = `g;

                // note start !
                12'd344:    toneL = `g; 12'd345:    toneL = `g;
                12'd346:    toneL = `g; 12'd347:    toneL = `g;
                12'd348:    toneL = `g; 12'd349:    toneL = `g;
                12'd350:    toneL = `g; 12'd351:    toneL = `g;

                // note start !
                12'd352:    toneL = `e; 12'd353:    toneL = `e;
                12'd354:    toneL = `e; 12'd355:    toneL = `e;
                12'd356:    toneL = `e; 12'd357:    toneL = `e;
                12'd358:    toneL = `e; 12'd359:    toneL = `e;

                // note start !
                12'd360:    toneL = `gs;    12'd361:    toneL = `gs;
                12'd362:    toneL = `gs;    12'd363:    toneL = `gs;
                12'd364:    toneL = `gs;    12'd365:    toneL = `gs;
                12'd366:    toneL = `gs;    12'd367:    toneL = `gs;

                // note start !
                12'd368:    toneL = `b; 12'd369:    toneL = `b;
                12'd370:    toneL = `b; 12'd371:    toneL = `b;
                12'd372:    toneL = `b; 12'd373:    toneL = `b;
                12'd374:    toneL = `b; 12'd375:    toneL = `b;

                // note start !
                12'd376:    toneL = `a; 12'd377:    toneL = `a;
                12'd378:    toneL = `a; 12'd379:    toneL = `a;
                12'd380:    toneL = `a; 12'd381:    toneL = `a;
                12'd382:    toneL = `a; 12'd383:    toneL = `a;

                // note start !
                12'd384:    toneL = `a; 12'd385:    toneL = `a;
                12'd386:    toneL = `a; 12'd387:    toneL = `a;
                12'd388:    toneL = `a; 12'd389:    toneL = `a;
                12'd390:    toneL = `a; 12'd391:    toneL = `a;

                // note start !
                12'd392:    toneL = `e; 12'd393:    toneL = `e;
                12'd394:    toneL = `e; 12'd395:    toneL = `e;
                12'd396:    toneL = `e; 12'd397:    toneL = `e;
                12'd398:    toneL = `e; 12'd399:    toneL = `e;

                // note start !
                12'd400:    toneL = `a; 12'd401:    toneL = `a;
                12'd402:    toneL = `a; 12'd403:    toneL = `a;
                12'd404:    toneL = `a; 12'd405:    toneL = `a;
                12'd406:    toneL = `a; 12'd407:    toneL = `a;

                // note start !
                12'd408:    toneL = `a; 12'd409:    toneL = `a;
                12'd410:    toneL = `a; 12'd411:    toneL = `a;
                12'd412:    toneL = `a; 12'd413:    toneL = `a;
                12'd414:    toneL = `a; 12'd415:    toneL = `a;

                // note start !
                12'd416:    toneL = `a; 12'd417:    toneL = `a;
                12'd418:    toneL = `a; 12'd419:    toneL = `a;
                12'd420:    toneL = `a; 12'd421:    toneL = `a;
                12'd422:    toneL = `a; 12'd423:    toneL = `a;

                // note start !
                12'd424:    toneL = `he;    12'd425:    toneL = `he;
                12'd426:    toneL = `he;    12'd427:    toneL = `he;
                12'd428:    toneL = `he;    12'd429:    toneL = `he;
                12'd430:    toneL = `he;    12'd431:    toneL = `he;

                // note start !
                12'd432:    toneL = `hc;    12'd433:    toneL = `hc;
                12'd434:    toneL = `hc;    12'd435:    toneL = `hc;
                12'd436:    toneL = `hc;    12'd437:    toneL = `hc;
                12'd438:    toneL = `hc;    12'd439:    toneL = `hc;

                // note start !
                12'd440:    toneL = `a; 12'd441:    toneL = `a;
                12'd442:    toneL = `a; 12'd443:    toneL = `a;
                12'd444:    toneL = `a; 12'd445:    toneL = `a;
                12'd446:    toneL = `a; 12'd447:    toneL = `a;

                // note start !
                12'd448:    toneL = `c; 12'd449:    toneL = `c;
                12'd450:    toneL = `c; 12'd451:    toneL = `c;
                12'd452:    toneL = `c; 12'd453:    toneL = `c;
                12'd454:    toneL = `c; 12'd455:    toneL = `c;

                // note start !
                12'd456:    toneL = `e; 12'd457:    toneL = `e;
                12'd458:    toneL = `e; 12'd459:    toneL = `e;
                12'd460:    toneL = `e; 12'd461:    toneL = `e;
                12'd462:    toneL = `e; 12'd463:    toneL = `e;

                // note start !
                12'd464:    toneL = `a; 12'd465:    toneL = `a;
                12'd466:    toneL = `a; 12'd467:    toneL = `a;
                12'd468:    toneL = `a; 12'd469:    toneL = `a;
                12'd470:    toneL = `a; 12'd471:    toneL = `a;

                // note start !
                12'd472:    toneL = `hc;    12'd473:    toneL = `hc;
                12'd474:    toneL = `hc;    12'd475:    toneL = `hc;
                12'd476:    toneL = `hc;    12'd477:    toneL = `hc;
                12'd478:    toneL = `hc;    12'd479:    toneL = `hc;

                // note start !
                12'd480:    toneL = `hd;    12'd481:    toneL = `hd;
                12'd482:    toneL = `hd;    12'd483:    toneL = `hd;
                12'd484:    toneL = `hd;    12'd485:    toneL = `hd;
                12'd486:    toneL = `hd;    12'd487:    toneL = `hd;

                // note start !
                12'd488:    toneL = `g; 12'd489:    toneL = `g;
                12'd490:    toneL = `g; 12'd491:    toneL = `g;
                12'd492:    toneL = `g; 12'd493:    toneL = `g;
                12'd494:    toneL = `g; 12'd495:    toneL = `g;

                // note start !
                12'd496:    toneL = `b; 12'd497:    toneL = `b;
                12'd498:    toneL = `b; 12'd499:    toneL = `b;
                12'd500:    toneL = `b; 12'd501:    toneL = `b;
                12'd502:    toneL = `b; 12'd503:    toneL = `b;

                // note start !
                12'd504:    toneL = `sil;   12'd505:    toneL = `sil;
                12'd506:    toneL = `sil;   12'd507:    toneL = `sil;
                12'd508:    toneL = `sil;   12'd509:    toneL = `sil;
                12'd510:    toneL = `sil;   12'd511:    toneL = `sil;

                // note start !
                12'd512:    toneL = `hc;    12'd513:    toneL = `hc;
                12'd514:    toneL = `hc;    12'd515:    toneL = `hc;
                12'd516:    toneL = `hc;    12'd517:    toneL = `hc;
                12'd518:    toneL = `hc;    12'd519:    toneL = `hc;

                // note start !
                12'd520:    toneL = `hc;    12'd521:    toneL = `hc;
                12'd522:    toneL = `hc;    12'd523:    toneL = `hc;
                12'd524:    toneL = `hc;    12'd525:    toneL = `hc;
                12'd526:    toneL = `hc;    12'd527:    toneL = `hc;

                // note start !
                12'd528:    toneL = `hc;    12'd529:    toneL = `hc;
                12'd530:    toneL = `hc;    12'd531:    toneL = `hc;
                12'd532:    toneL = `hc;    12'd533:    toneL = `hc;
                12'd534:    toneL = `hc;    12'd535:    toneL = `hc;

                // note start !
                12'd536:    toneL = `hc;    12'd537:    toneL = `hc;
                12'd538:    toneL = `hc;    12'd539:    toneL = `hc;
                12'd540:    toneL = `hc;    12'd541:    toneL = `hc;
                12'd542:    toneL = `hc;    12'd543:    toneL = `hc;

                // note start !
                12'd544:    toneL = `sil;   12'd545:    toneL = `sil;
                12'd546:    toneL = `sil;   12'd547:    toneL = `sil;
                12'd548:    toneL = `sil;   12'd549:    toneL = `sil;
                12'd550:    toneL = `sil;   12'd551:    toneL = `sil;

                // note start !
                12'd552:    toneL = `sil;   12'd553:    toneL = `sil;
                12'd554:    toneL = `sil;   12'd555:    toneL = `sil;
                12'd556:    toneL = `sil;   12'd557:    toneL = `sil;
                12'd558:    toneL = `sil;   12'd559:    toneL = `sil;

                // note start !
                12'd560:    toneL = `sil;   12'd561:    toneL = `sil;
                12'd562:    toneL = `sil;   12'd563:    toneL = `sil;
                12'd564:    toneL = `sil;   12'd565:    toneL = `sil;
                12'd566:    toneL = `sil;   12'd567:    toneL = `sil;

                // note start !
                12'd568:    toneL = `sil;   12'd569:    toneL = `sil;
                12'd570:    toneL = `sil;   12'd571:    toneL = `sil;
                12'd572:    toneL = `sil;   12'd573:    toneL = `sil;
                12'd574:    toneL = `sil;   12'd575:    toneL = `sil;



                default : toneL = `sil;
            endcase
        end
        else begin
            case (ibeatNum)
                // note start !
                12'd0:  toneL = `hd;    12'd1:  toneL = `hd;
                12'd2:  toneL = `hd;    12'd3:  toneL = `hd;
                12'd4:  toneL = `hd;    12'd5:  toneL = `hd;
                12'd6:  toneL = `hd;    12'd7:  toneL = `hd;

                // note start !
                12'd8:  toneL = `hd;    12'd9:  toneL = `hd;
                12'd10: toneL = `hd;    12'd11: toneL = `hd;
                12'd12: toneL = `hd;    12'd13: toneL = `hd;
                12'd14: toneL = `hd;    12'd15: toneL = `hd;

                // note start !
                12'd16: toneL = `hd;    12'd17: toneL = `hd;
                12'd18: toneL = `hd;    12'd19: toneL = `hd;
                12'd20: toneL = `hd;    12'd21: toneL = `hd;
                12'd22: toneL = `hd;    12'd23: toneL = `hd;

                // note start !
                12'd24: toneL = `hd;    12'd25: toneL = `hd;
                12'd26: toneL = `hd;    12'd27: toneL = `hd;
                12'd28: toneL = `hd;    12'd29: toneL = `hd;
                12'd30: toneL = `hd;    12'd31: toneL = `hd;

                // note start !
                12'd32: toneL = `a; 12'd33: toneL = `a;
                12'd34: toneL = `a; 12'd35: toneL = `a;
                12'd36: toneL = `a; 12'd37: toneL = `a;
                12'd38: toneL = `a; 12'd39: toneL = `a;

                // note start !
                12'd40: toneL = `a; 12'd41: toneL = `a;
                12'd42: toneL = `a; 12'd43: toneL = `a;
                12'd44: toneL = `a; 12'd45: toneL = `a;
                12'd46: toneL = `a; 12'd47: toneL = `a;

                // note start !
                12'd48: toneL = `a; 12'd49: toneL = `a;
                12'd50: toneL = `a; 12'd51: toneL = `a;
                12'd52: toneL = `a; 12'd53: toneL = `a;
                12'd54: toneL = `a; 12'd55: toneL = `a;

                // note start !
                12'd56: toneL = `a; 12'd57: toneL = `a;
                12'd58: toneL = `a; 12'd59: toneL = `a;
                12'd60: toneL = `a; 12'd61: toneL = `a;
                12'd62: toneL = `a; 12'd63: toneL = `a;

                // note start !
                12'd64: toneL = `b; 12'd65: toneL = `b;
                12'd66: toneL = `b; 12'd67: toneL = `b;
                12'd68: toneL = `b; 12'd69: toneL = `b;
                12'd70: toneL = `b; 12'd71: toneL = `b;

                // note start !
                12'd72: toneL = `b; 12'd73: toneL = `b;
                12'd74: toneL = `b; 12'd75: toneL = `b;
                12'd76: toneL = `b; 12'd77: toneL = `b;
                12'd78: toneL = `b; 12'd79: toneL = `b;

                // note start !
                12'd80: toneL = `b; 12'd81: toneL = `b;
                12'd82: toneL = `b; 12'd83: toneL = `b;
                12'd84: toneL = `b; 12'd85: toneL = `b;
                12'd86: toneL = `b; 12'd87: toneL = `b;

                // note start !
                12'd88: toneL = `b; 12'd89: toneL = `b;
                12'd90: toneL = `b; 12'd91: toneL = `b;
                12'd92: toneL = `b; 12'd93: toneL = `b;
                12'd94: toneL = `b; 12'd95: toneL = `b;

                // note start !
                12'd96: toneL = `f; 12'd97: toneL = `f;
                12'd98: toneL = `f; 12'd99: toneL = `f;
                12'd100:    toneL = `f; 12'd101:    toneL = `f;
                12'd102:    toneL = `f; 12'd103:    toneL = `f;

                // note start !
                12'd104:    toneL = `f; 12'd105:    toneL = `f;
                12'd106:    toneL = `f; 12'd107:    toneL = `f;
                12'd108:    toneL = `f; 12'd109:    toneL = `f;
                12'd110:    toneL = `f; 12'd111:    toneL = `f;

                // note start !
                12'd112:    toneL = `f; 12'd113:    toneL = `f;
                12'd114:    toneL = `f; 12'd115:    toneL = `f;
                12'd116:    toneL = `f; 12'd117:    toneL = `f;
                12'd118:    toneL = `f; 12'd119:    toneL = `f;

                // note start !
                12'd120:    toneL = `f; 12'd121:    toneL = `f;
                12'd122:    toneL = `f; 12'd123:    toneL = `f;
                12'd124:    toneL = `f; 12'd125:    toneL = `f;
                12'd126:    toneL = `f; 12'd127:    toneL = `f;

                // note start !
                12'd128:    toneL = `g; 12'd129:    toneL = `g;
                12'd130:    toneL = `g; 12'd131:    toneL = `g;
                12'd132:    toneL = `g; 12'd133:    toneL = `g;
                12'd134:    toneL = `g; 12'd135:    toneL = `g;

                // note start !
                12'd136:    toneL = `g; 12'd137:    toneL = `g;
                12'd138:    toneL = `g; 12'd139:    toneL = `g;
                12'd140:    toneL = `g; 12'd141:    toneL = `g;
                12'd142:    toneL = `g; 12'd143:    toneL = `g;

                // note start !
                12'd144:    toneL = `g; 12'd145:    toneL = `g;
                12'd146:    toneL = `g; 12'd147:    toneL = `g;
                12'd148:    toneL = `g; 12'd149:    toneL = `g;
                12'd150:    toneL = `g; 12'd151:    toneL = `g;

                // note start !
                12'd152:    toneL = `g; 12'd153:    toneL = `g;
                12'd154:    toneL = `g; 12'd155:    toneL = `g;
                12'd156:    toneL = `g; 12'd157:    toneL = `g;
                12'd158:    toneL = `g; 12'd159:    toneL = `g;

                // note start !
                12'd160:    toneL = `d; 12'd161:    toneL = `d;
                12'd162:    toneL = `d; 12'd163:    toneL = `d;
                12'd164:    toneL = `d; 12'd165:    toneL = `d;
                12'd166:    toneL = `d; 12'd167:    toneL = `d;

                // note start !
                12'd168:    toneL = `d; 12'd169:    toneL = `d;
                12'd170:    toneL = `d; 12'd171:    toneL = `d;
                12'd172:    toneL = `d; 12'd173:    toneL = `d;
                12'd174:    toneL = `d; 12'd175:    toneL = `d;

                // note start !
                12'd176:    toneL = `d; 12'd177:    toneL = `d;
                12'd178:    toneL = `d; 12'd179:    toneL = `d;
                12'd180:    toneL = `d; 12'd181:    toneL = `d;
                12'd182:    toneL = `d; 12'd183:    toneL = `d;

                // note start !
                12'd184:    toneL = `d; 12'd185:    toneL = `d;
                12'd186:    toneL = `d; 12'd187:    toneL = `d;
                12'd188:    toneL = `d; 12'd189:    toneL = `d;
                12'd190:    toneL = `d; 12'd191:    toneL = `d;

                // note start !
                12'd192:    toneL = `g; 12'd193:    toneL = `g;
                12'd194:    toneL = `g; 12'd195:    toneL = `g;
                12'd196:    toneL = `g; 12'd197:    toneL = `g;
                12'd198:    toneL = `g; 12'd199:    toneL = `g;

                // note start !
                12'd200:    toneL = `g; 12'd201:    toneL = `g;
                12'd202:    toneL = `g; 12'd203:    toneL = `g;
                12'd204:    toneL = `g; 12'd205:    toneL = `g;
                12'd206:    toneL = `g; 12'd207:    toneL = `g;

                // note start !
                12'd208:    toneL = `g; 12'd209:    toneL = `g;
                12'd210:    toneL = `g; 12'd211:    toneL = `g;
                12'd212:    toneL = `g; 12'd213:    toneL = `g;
                12'd214:    toneL = `g; 12'd215:    toneL = `g;

                // note start !
                12'd216:    toneL = `g; 12'd217:    toneL = `g;
                12'd218:    toneL = `g; 12'd219:    toneL = `g;
                12'd220:    toneL = `g; 12'd221:    toneL = `g;
                12'd222:    toneL = `g; 12'd223:    toneL = `g;

                // note start !
                12'd224:    toneL = `a; 12'd225:    toneL = `a;
                12'd226:    toneL = `a; 12'd227:    toneL = `a;
                12'd228:    toneL = `a; 12'd229:    toneL = `a;
                12'd230:    toneL = `a; 12'd231:    toneL = `a;

                // note start !
                12'd232:    toneL = `a; 12'd233:    toneL = `a;
                12'd234:    toneL = `a; 12'd235:    toneL = `a;
                12'd236:    toneL = `a; 12'd237:    toneL = `a;
                12'd238:    toneL = `a; 12'd239:    toneL = `a;

                // note start !
                12'd240:    toneL = `a; 12'd241:    toneL = `a;
                12'd242:    toneL = `a; 12'd243:    toneL = `a;
                12'd244:    toneL = `a; 12'd245:    toneL = `a;
                12'd246:    toneL = `a; 12'd247:    toneL = `a;

                // note start !
                12'd248:    toneL = `a; 12'd249:    toneL = `a;
                12'd250:    toneL = `a; 12'd251:    toneL = `a;
                12'd252:    toneL = `a; 12'd253:    toneL = `a;
                12'd254:    toneL = `a; 12'd255:    toneL = `a;

                // note start !
                12'd256:    toneL = `ha;    12'd257:    toneL = `ha;
                12'd258:    toneL = `ha;    12'd259:    toneL = `ha;
                12'd260:    toneL = `ha;    12'd261:    toneL = `ha;
                12'd262:    toneL = `ha;    12'd263:    toneL = `ha;

                // note start !
                12'd264:    toneL = `hfs;   12'd265:    toneL = `hfs;
                12'd266:    toneL = `hfs;   12'd267:    toneL = `hfs;
                12'd268:    toneL = `hg;   12'd269:    toneL = `hg;
                12'd270:    toneL = `hg;   12'd271:    toneL = `hg;

                // note start !
                12'd272:    toneL = `ha;    12'd273:    toneL = `ha;
                12'd274:    toneL = `ha;    12'd275:    toneL = `ha;
                12'd276:    toneL = `ha;    12'd277:    toneL = `ha;
                12'd278:    toneL = `ha;    12'd279:    toneL = `ha;

                // note start !
                12'd280:    toneL = `hfs;   12'd281:    toneL = `hfs;
                12'd282:    toneL = `hfs;   12'd283:    toneL = `hfs;
                12'd284:    toneL = `hg;   12'd285:    toneL = `hg;
                12'd286:    toneL = `hg;   12'd287:    toneL = `hg;

                // note start !
                12'd288:    toneL = `ha;    12'd289:    toneL = `ha;
                12'd290:    toneL = `ha;    12'd291:    toneL = `ha;
                12'd292:    toneL = `a;    12'd293:    toneL = `a;
                12'd294:    toneL = `a;    12'd295:    toneL = `a;

                // note start !
                12'd296:    toneL = `b; 12'd297:    toneL = `b;
                12'd298:    toneL = `b; 12'd299:    toneL = `b;
                12'd300:    toneL = `hcs; 12'd301:    toneL = `hcs;
                12'd302:    toneL = `hcs; 12'd303:    toneL = `hcs;

                // note start !
                12'd304:    toneL = `hd;    12'd305:    toneL = `hd;
                12'd306:    toneL = `hd;    12'd307:    toneL = `hd;
                12'd308:    toneL = `he;    12'd309:    toneL = `he;
                12'd310:    toneL = `he;    12'd311:    toneL = `he;

                // note start !
                12'd312:    toneL = `hfs;   12'd313:    toneL = `hfs;
                12'd314:    toneL = `hfs;   12'd315:    toneL = `hfs;
                12'd316:    toneL = `hg;   12'd317:    toneL = `hg;
                12'd318:    toneL = `hg;   12'd319:    toneL = `hg;

                // note start !
                12'd320:    toneL = `hfs;   12'd321:    toneL = `hfs;
                12'd322:    toneL = `hfs;   12'd323:    toneL = `hfs;
                12'd324:    toneL = `hfs;   12'd325:    toneL = `hfs;
                12'd326:    toneL = `hfs;   12'd327:    toneL = `hfs;

                // note start !
                12'd328:    toneL = `hd;    12'd329:    toneL = `hd;
                12'd330:    toneL = `hd;    12'd331:    toneL = `hd;
                12'd332:    toneL = `he;    12'd333:    toneL = `he;
                12'd334:    toneL = `he;    12'd335:    toneL = `he;

                // note start !
                12'd336:    toneL = `hfs;   12'd337:    toneL = `hfs;
                12'd338:    toneL = `hfs;   12'd339:    toneL = `hfs;
                12'd340:    toneL = `hfs;   12'd341:    toneL = `hfs;
                12'd342:    toneL = `hfs;   12'd343:    toneL = `hfs;

                // note start !
                12'd344:    toneL = `f; 12'd345:    toneL = `f;
                12'd346:    toneL = `f; 12'd347:    toneL = `f;
                12'd348:    toneL = `g; 12'd349:    toneL = `g;
                12'd350:    toneL = `g; 12'd351:    toneL = `g;

                // note start !
                12'd352:    toneL = `a; 12'd353:    toneL = `a;
                12'd354:    toneL = `a; 12'd355:    toneL = `a;
                12'd356:    toneL = `b; 12'd357:    toneL = `b;
                12'd358:    toneL = `b; 12'd359:    toneL = `b;

                // note start !
                12'd360:    toneL = `a; 12'd361:    toneL = `a;
                12'd362:    toneL = `a; 12'd363:    toneL = `a;
                12'd364:    toneL = `g; 12'd365:    toneL = `g;
                12'd366:    toneL = `g; 12'd367:    toneL = `g;

                // note start !
                12'd368:    toneL = `a; 12'd369:    toneL = `a;
                12'd370:    toneL = `a; 12'd371:    toneL = `a;
                12'd372:    toneL = `f; 12'd373:    toneL = `f;
                12'd374:    toneL = `f; 12'd375:    toneL = `f;

                // note start !
                12'd376:    toneL = `g; 12'd377:    toneL = `g;
                12'd378:    toneL = `g; 12'd379:    toneL = `g;
                12'd380:    toneL = `a; 12'd381:    toneL = `a;
                12'd382:    toneL = `a; 12'd383:    toneL = `a;

                // note start !
                12'd384:    toneL = `g; 12'd385:    toneL = `g;
                12'd386:    toneL = `g; 12'd387:    toneL = `g;
                12'd388:    toneL = `g; 12'd389:    toneL = `g;
                12'd390:    toneL = `g; 12'd391:    toneL = `g;

                // note start !
                12'd392:    toneL = `b; 12'd393:    toneL = `b;
                12'd394:    toneL = `b; 12'd395:    toneL = `b;
                12'd396:    toneL = `a; 12'd397:    toneL = `a;
                12'd398:    toneL = `a; 12'd399:    toneL = `a;

                // note start !
                12'd400:    toneL = `g; 12'd401:    toneL = `g;
                12'd402:    toneL = `g; 12'd403:    toneL = `g;
                12'd404:    toneL = `g; 12'd405:    toneL = `g;
                12'd406:    toneL = `g; 12'd407:    toneL = `g;

                // note start !
                12'd408:    toneL = `f; 12'd409:    toneL = `f;
                12'd410:    toneL = `f; 12'd411:    toneL = `f;
                12'd412:    toneL = `e; 12'd413:    toneL = `e;
                12'd414:    toneL = `e; 12'd415:    toneL = `e;

                // note start !
                12'd416:    toneL = `f; 12'd417:    toneL = `f;
                12'd418:    toneL = `f; 12'd419:    toneL = `f;
                12'd420:    toneL = `e; 12'd421:    toneL = `e;
                12'd422:    toneL = `e; 12'd423:    toneL = `e;

                // note start !
                12'd424:    toneL = `d; 12'd425:    toneL = `d;
                12'd426:    toneL = `d; 12'd427:    toneL = `d;
                12'd428:    toneL = `e; 12'd429:    toneL = `e;
                12'd430:    toneL = `e; 12'd431:    toneL = `e;

                // note start !
                12'd432:    toneL = `f; 12'd433:    toneL = `f;
                12'd434:    toneL = `f; 12'd435:    toneL = `f;
                12'd436:    toneL = `g; 12'd437:    toneL = `g;
                12'd438:    toneL = `g; 12'd439:    toneL = `g;

                // note start !
                12'd440:    toneL = `a; 12'd441:    toneL = `a;
                12'd442:    toneL = `a; 12'd443:    toneL = `a;
                12'd444:    toneL = `b; 12'd445:    toneL = `b;
                12'd446:    toneL = `b; 12'd447:    toneL = `b;

                // note start !
                12'd448:    toneL = `g; 12'd449:    toneL = `g;
                12'd450:    toneL = `g; 12'd451:    toneL = `g;
                12'd452:    toneL = `g; 12'd453:    toneL = `g;
                12'd454:    toneL = `g; 12'd455:    toneL = `g;

                // note start !
                12'd456:    toneL = `b; 12'd457:    toneL = `b;
                12'd458:    toneL = `b; 12'd459:    toneL = `b;
                12'd460:    toneL = `a; 12'd461:    toneL = `a;
                12'd462:    toneL = `a; 12'd463:    toneL = `a;

                // note start !
                12'd464:    toneL = `b; 12'd465:    toneL = `b;
                12'd466:    toneL = `b; 12'd467:    toneL = `b;
                12'd468:    toneL = `b; 12'd469:    toneL = `b;
                12'd470:    toneL = `b; 12'd471:    toneL = `b;

                // note start !
                12'd472:    toneL = `hcs;   12'd473:    toneL = `hcs;
                12'd474:    toneL = `hcs;   12'd475:    toneL = `hcs;
                12'd476:    toneL = `hd;   12'd477:    toneL = `hd;
                12'd478:    toneL = `hd;   12'd479:    toneL = `hd;

                // note start !
                12'd480:    toneL = `a; 12'd481:    toneL = `a;
                12'd482:    toneL = `a; 12'd483:    toneL = `a;
                12'd484:    toneL = `b; 12'd485:    toneL = `b;
                12'd486:    toneL = `b; 12'd487:    toneL = `b;

                // note start !
                12'd488:    toneL = `hcs;   12'd489:    toneL = `hcs;
                12'd490:    toneL = `hcs;   12'd491:    toneL = `hcs;
                12'd492:    toneL = `hd;   12'd493:    toneL = `hd;
                12'd494:    toneL = `hd;   12'd495:    toneL = `hd;

                // note start !
                12'd496:    toneL = `he;    12'd497:    toneL = `he;
                12'd498:    toneL = `he;    12'd499:    toneL = `he;
                12'd500:    toneL = `hfs;    12'd501:    toneL = `hfs;
                12'd502:    toneL = `hfs;    12'd503:    toneL = `hfs;

                // note start !
                12'd504:    toneL = `hg;    12'd505:    toneL = `hg;
                12'd506:    toneL = `hg;    12'd507:    toneL = `hg;
                12'd508:    toneL = `ha;    12'd509:    toneL = `ha;
                12'd510:    toneL = `ha;    12'd511:    toneL = `ha;

                default : toneL = `sil; 
            endcase
        end
    end
endmodule
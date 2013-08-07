// /d/city/zhonglieci.c  忠烈祠
//modified by sega 1/10/99
//修改a_time为120,并添加newjob的一些信息,以防一些人一直flood
//修改a_time为300，一些老玩家建议我们延长这个时间。
//修改了2次保镖间隔为5分钟
#include <ansi.h>
#define A_TIME 300 
inherit ROOM;

string * add_msg = ({
	"/d/city/siqiaoyanyu",		// 四桥烟雨
	"/d/city2/wangfu1",		// 王府井大街
	"/d/city3/wangjianglou",	// 望江楼
	"/d/suzhou/canlangting",	// 沧浪亭
	"/d/hangzhou/liulangqiao",	// 柳浪桥
	"/d/fuzhou/yongquan",		// 涌泉寺
	"/d/xiangyang/nixianglou",	// 觅香楼
	"/d/lingzhou/luorilin1",	// 落日林
	"/d/dali/feilihu",		// 妃丽湖畔
	"/d/village/temple1",		// 玄坛庙
//	"/d/shaolin/qyping",		// 青云坪
	"/d/wudang/sanqingdian",	// 三清殿
	"/d/jiangling/chenglingji",	// 城陵矶
	"/d/emei/duguangtai",		// 睹光台
	"/d/qingcheng/huyingting",	// 呼应亭
	"/d/songshan/luyanpubu",	// 芦岩瀑布
	"/d/taishan/tanhai",		// 探海石
	"/d/huashan/ziqitai",		// 紫气台
	"/d/henshan/liuyunping",	// 流云坪
	"/d/hengshan/tongyuangu",	// 通元谷
	"/d/mingjiao/shanlu3",		// 悬天崖
	"/d/heimuya/xingxingtan",	// 猩猩滩
	"/d/xuedao/wangyougu",		// 忘忧谷
	"/d/gumu/taiyi1",		// 太乙池
//	"/d/taohua/xiuxishi",		// 桃花轩
	"/d/baituo/zhuyuan",		// 竹园
	"/d/xiaoyao/qingcaop",		// 青草坪
	"/d/xiaoyao/pubu",		// 玉壁瀑布
//	"/d/lingjiu/daban",		// 缀锦阁
//	"/d/xingxiu/yueerquan",		// 月儿泉
	"/d/xueshan/cangjingge",	// 雪山藏经室
	"/d/wudujiao/taohua",		// 桃花峪
	"/d/wuliang/jianhugong",	// 剑湖宫
        "/d/jiangling/shennongjia",     // 神农架
        "/d/kunlun/kuhanlou",           // 苦寒楼
        "/d/shaolin/damodong",          // 达摩洞
        "/d/wudang/shierliantai",       // 十二莲台
        "/d/qingcheng/maguchi",         // 麻姑池
        "/d/lanzhou/cuiying",           // 翠英门
        "/d/city/ouyangci",             // 欧阳祠
	"/d/tianlongsi/yuhuayuan",	// 雨花院
	"/d/yanziwu/tingxiang",		// 听香水榭
        "/d/quanzhen/shijianyan",       // 试剑岩
        "/d/lingzhou/luorilin1",        // 落日林
        "/d/huanghe/wuqiao",            // 乌鞘岭
        "/d/changcheng/fenghuotai1-2",  // 烽火台
        "/d/changcheng/fenghuotai1-1",  // 烽火台
	"/d/meizhuang/xiaoyuan",	// 琴音小院
	"/d/shiliang/tingzi",		// 玫瑰小亭
});

void create()
{
	set("short", "忠烈祠");
	set("long", @LONG
这里扬州忠烈祠，是大清鹿鼎公韦小宝奉清圣祖康熙圣谕所筑，供
奉的却是大明尽忠报国、忠君爱民的扬州督师史阁部史可法。堂上牌匾
是康熙御笔“敕建扬州忠烈祠”。匾下史公神像历久年深，像上的颜色
已经班驳脱离了。四周的地上积了一些尘土，看来象是已经有些时候没
有人来过的痕迹。像前摆放着一张红木高脚供桌，桌上高处，放着一个
神龛(kan)。
LONG    );
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
	     "northeast" : __DIR__"caohebeijie",
	]));

	set("count",1);
	set("item_desc", ([
		"kan" :  HIG"
与周遭一比较，你发现这个神龛一尘不染，干净得奇怪，好象常有人打开似的。\n
"NOR
	]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_open","dakai");
	add_action("do_open","open");

	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}

int do_open(string arg)
{
	object me = this_player();
	object ob,rz;
	string src_add,dest_add,des;
	object room,room2;

	src_add=add_msg[random(sizeof(add_msg))];
	dest_add=add_msg[random(sizeof(add_msg))];
	while (dest_add == src_add)
		dest_add=add_msg[random(sizeof(add_msg))];

	if (!arg || arg != "kan" )
		return 0;

	if (me->query_skill("dodge", 1) < 80)
		return notify_fail("神龛太高了，你的轻功够不着。\n");

	if ( !wizardp(me) && time() - me->query("baobiaotime") < 300)
		return notify_fail("你的上个任务完成了？辛苦辛苦。歇会吧。\n");

	if (query("count") > 0) {
		if (!present("mi ling",me) ) {
			if (! room = find_object(src_add) )
				room = load_object(src_add);
			rz = new(__DIR__"npc/renzhi");
			rz -> set("leader_name", me->query("id") );
			rz -> set("title",me->query("name")+"所保护的人质");
			rz -> set("dest_add",dest_add);
			rz -> move(room);
			if (! room2 = find_object(dest_add) )
				room2 = load_object(dest_add);
			des = "护送" + room->query("short") + "那里的" + rz->query("name") + "到达" + room2->query("short") ;
			ob = new(__DIR__"obj/miling");
			ob -> set("describe",des);
			ob -> set("src_add",room->query("short") );
			ob -> set("dest_add",room2->query("short") );
			ob -> set("src_des",room->query("outdoors") );
			ob -> set("dest_des",room2->query("outdoors") );
			ob -> move(me);
			me -> set("baobiaotime", time());
			add("count",-1);
message_vision(HIY"$N小心翼翼地打开神龛，发现了一卷纸垫夹在龛门后木缝里，便顺手取出来揣进怀中。\n"NOR,me);
			return 1;
		}
		else
		{
message_vision(YEL"$N试着要打开神龛，一不小心，结果‘轰’的一下供桌给碰倒了。\n"NOR,me);
			return 1;
		}
	}
	else {
message_vision(HIG"$N小心翼翼地打开神龛，发现了里面啥都没有。还有谁会来这呢？明天再来吧。\n"NOR,me);
		return 1;
	}
}

void newjob()
{
	object room;
	if (query("count") <= 0) {
		if( room = find_object(__DIR__"zhonglieci") )
		message("vision",YEL"只见一个行迹可疑的灰衣人闪了进来，在神龛那里捣鼓了几下，慌里慌张的走了。\n"NOR,room);
		add("count",1);
	}
	remove_call_out("newjob");
	call_out("newjob",A_TIME);
}


// Room: /yangzhou/xiaosquare.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "С�㳡");
	set("long", @LONG
����֪�����Ŷ�ǽ���һƬС�ճ���Ҳ�������������֮�������
����������ɱ֮�����ڹ㳡����ĸ�ʾǽ�ϣ����˼��Źٸ�����׽�ó�
͢Ҫ���ĺ������飬����Χ������࿴���ֵ��ˣ����в���һЩ���ָ�
�֣�����Ҫ׽�õ�Ҫ���������֣������������Ұ񡣵�Ҳ�в�������
����֮����һ��ԾԾ���ԡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"caohebeijie",
		"south" : __DIR__"caohexiaojie",
	]));
	set("outdoors", "yangzhouw");
	set("objects", ([
//		__DIR__"npc/yachai" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

mapping *quest = ({
({
	([	"name"	:	"������С",
		"id"	:	"jianghu  xiaoxiao",
		"where"	:	__DIR__"task1/xiaoxiao",]),
	([	"name"	:	"ɽ��",
		"id"	:	"shan  zei",
		"where"	:	__DIR__"task1/shanzei",]),
}),
({
	([	"name"	:	"ɽ��",
		"id"	:	"shan  zei",
		"where"	:	__DIR__"task1/shanzei",]),
	([	"name"	:	"��һ��",
		"id"	:	"gai  yiming",
		"where"	:	__DIR__"task1/gaiyiming",]),
	([	"name"	:	"������",
		"id"	:	"chang  changfeng",
		"where"	:	__DIR__"task1/chang",]),
	([	"name"	:	"����Ӱ",
		"id"	:	"hua  jianying",
		"where"	:	__DIR__"task1/hua",]),
	([	"name"	:	"��ң��",
		"id"	:	"xiaoyao  zi",
		"where"	:	__DIR__"task1/xiao",]),
	([	"name"	:	"�������",
		"id"	:	"huangxu  daoren",
		"where"	:	__DIR__"task1/huangxu",]),
	([	"name"	:	"��ɮ",
		"id"	:	"e  seng",
		"where"	:	__DIR__"task1/eseng",]),
	([	"name"	:	"�ܻ���",
		"id"	:	"cao  huachun",
		"where"	:	__DIR__"task1/cao",]),
	([	"name"	:	"�찲��",
		"id"	:	"zhu  anguo",
		"where"	:	__DIR__"task1/zhu",]),
}),
({
	([	"name"	:	"������",
		"id"	:	"jiangyang  dadao",
		"where"	:	__DIR__"task1/dadao",]),
	([	"name"	:	"�ݿ�",
		"id"	:	"cao  kou",
		"where"	:	__DIR__"task1/caokou",]),
	([	"name"	:	"���",
		"id"	:	"e  ba",
		"where"	:	__DIR__"task1/eba",]),
//	([	"name"	:	"����",
//		"id"	:	"song  yang",
//		"where"	:	__DIR__"task1/songyang",]),
	([	"name"	:	"ȫ����",
		"id"	:	"quan  erfeng",
		"where"	:	__DIR__"task1/quan",]),
	([	"name"	:	"������",
		"id"	:	"meng  zhengpeng",
		"where"	:	__DIR__"task1/meng",]),
	([	"name"	:	"����ͨ",
		"id"	:	"xianyu  tong",
		"where"	:	__DIR__"task1/xian",]),
	([	"name"	:	"��",
		"id"	:	"mai  jing",
		"where"	:	__DIR__"task1/maijing",]),
	([	"name"	:	"����ȭ",
		"id"	:	"guo  sanquan",
		"where"	:	__DIR__"task1/guo",]),
}),
({
	([	"name"	:	"��һ��",
		"id"	:	"zhao  yishang",
		"where"	:	__DIR__"task1/zhao",]),
	([	"name"	:	"Ǯ����",
		"id"	:	"qian  erbai",
		"where"	:	__DIR__"task1/qian",]),	
	([	"name"	:	"������",
		"id"	:	"sun  sanhui",
		"where"	:	__DIR__"task1/sun",]),
	([	"name"	:	"���Ĵ�",
		"id"	:	"li  sicui",
		"where"	:	__DIR__"task1/li",]),
	([	"name"	:	"������",
		"id"	:	"zhou  wushu",
		"where"	:	__DIR__"task1/zhou",]),
	([	"name"	:	"������",
		"id"	:	"wu  liupo",
		"where"	:	__DIR__"task1/wu",]),
	([	"name"	:	"֣����",
		"id"	:	"zheng  qimie",
		"where"	:	__DIR__"task1/zheng",]),
	([	"name"	:	"����˥",
		"id"	:	"wang  bashuai",
		"where"	:	__DIR__"task1/wang",]),
	([	"name"	:	"Ԫ�㲨",
		"id"	:	"yuan  guangbo",
		"where"	:	__DIR__"task1/yuan",]),
	([	"name"	:	"�쳤��",
		"id"	:	"xu  zhanglao",
		"where"	:	__DIR__"task1/xu",]),
}),
({
	([	"name"	:	"����",
		"id"	:	"a  da",
		"where"	:	__DIR__"task1/ada",]),
	([	"name"	:	"����",
		"id"	:	"a  er",
		"where"	:	__DIR__"task1/aer",]),
	([	"name"	:	"����",
		"id"	:	"a  san",
		"where"	:	__DIR__"task1/asan",]),
	([	"name"	:	"������",
		"id"	:	"yu  zhenzi",
		"where"	:	__DIR__"task1/yu",]),	
	([	"name"	:	"������",
		"id"	:	"duan  yanqing",
		"where"	:	__DIR__"task1/duan",]),	
	([	"name"	:	"Ҷ����",
		"id"	:	"ye  erniang",
		"where"	:	__DIR__"task1/ye",]),	
	([	"name"	:	"�Ϻ�����",
		"id"	:	"nanhai  eshen",
		"where"	:	__DIR__"task1/nan",]),	
	([	"name"	:	"���к�",
		"id"	:	"yun  zhonghe",
		"where"	:	__DIR__"task1/yun",]),	
	([	"name"	:	"¹�ȿ�",
		"id"	:	"lu  zhangke",
		"where"	:	__DIR__"task1/lu",]),	
	([	"name"	:	"�ױ���",
		"id"	:	"he  biweng",
		"where"	:	__DIR__"task1/he",]),	
	([	"name"	:	"�����",
		"id"	:	"daerba  huofo",
		"where"	:	__DIR__"task1/daerba",]),	
	([	"name"	:	"����",
		"id"	:	"huo  du",
		"where"	:	__DIR__"task1/huodu",]),	
}),
});
mapping *wheres=({
	([	"chinese"	:	"����ɽ",
		"weizhi"	:	"/d/baituo/cao2",]),
	([	"chinese"	:	"����",
		"weizhi"	:	"/d/changcheng/changcheng19",]),
	([	"chinese"	:	"���ݳ�",
		"weizhi"	:	"/d/city/jiaowai9",]),
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/beijing/huayuan",]),
	([	"chinese"	:	"�ɶ���",
		"weizhi"	:	"/d/chengdu/wuhouci",]),
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/changan/gulou",]),  
	([	"chinese"	:	"�����",
		"weizhi"	:	"/d/dali/tingyuan",]),  
	([	"chinese"	:	"����ɽ",
		"weizhi"	:	"/d/emei/jieyindian",]),  
	([	"chinese"	:	"��ɽ��",
		"weizhi"	:	"/d/foshan/street3",]),
	([	"chinese"	:	"���ݳ�",
		"weizhi"	:	"/d/fuzhou/gushan",]),
	([	"chinese"	:	"����",
		"weizhi" 	:	"/d/guanwai/milin3",]),
	([	"chinese"	:	"���ݳ�",
		"weizhi"	:	"/d/hangzhou/shiwudong",]),
	([	"chinese"	:	"��ľ��",
		"weizhi"	:	"/d/heimuya/shijie1",]),
	([	"chinese"	:	"��ɽ",
		"weizhi"	:	"/d/hengshan/yuyang",]),
	([	"chinese"	:	"��ɽ",
		"weizhi"	:	"/d/henshan/nantaisi",]),  
	([	"chinese"	:	"�ƺ�",
		"weizhi"	:	"/d/huanghe/weifen",]),  
	([	"chinese"	:	"��ɽ",
		"weizhi"	:	"/d/huashan/yuntai",]),  
	([	"chinese"	:	"�����",
		"weizhi"	:	"/d/jiangling/longzhong",]),  
	([	"chinese"	:	"���˳�",
		"weizhi"	:	"/d/jiaxing/njroad5",]),  
	([	"chinese"	:	"����ɽ",
		"weizhi"	:	"/d/kunlun/jiuqulang2",]),  
	([	"chinese"	:	"���ݳ�",
		"weizhi"	:	"/d/lanzhou/street2",]),  
	([	"chinese"	:	"���շ�",
		"weizhi"	:	"/d/lingjiu/jian",]),  
	([	"chinese"	:	"���ݳ�",
		"weizhi"	:	"/d/lingzhou/kongdi",]),  
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/luoyang/wanghuating",]),  
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/mingjiao/tohtq3",]),  
	([	"chinese"	:	"����ɽ",
		"weizhi"	:	"/d/qilian/zhutishan",]),  
	([	"chinese"	:	"���ɽ",
		"weizhi"	:	"/d/qingcheng/huyingting",]),  
	([	"chinese"	:	"��ɽ",
		"weizhi"	:	"/d/songshan/junjigate",]),  
	([	"chinese"	:	"���ݳ�",
		"weizhi"	:	"/d/suzhou/liuyuan",]),  
	([	"chinese"	:	"̩ɽ",
		"weizhi"	:	"/d/taishan/tianjie",]),  	 
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/tianlongsi/tading",]),  
	([	"chinese"	:	"���Ʒ�",
		"weizhi"	:	"/d/tiezhang/guangchang",]),  
	([	"chinese"	:	"��ɽ��",
		"weizhi"	:	"/d/village/eexit",]),  
	([	"chinese"	:	"��ٹ�",
		"weizhi"	:	"/d/wanjiegu/port2",]),  
	([	"chinese"	:	"�嶾��",
		"weizhi"	:	"/d/wudujiao/wdsl3",]),  
	([	"chinese"	:	"����ɽ",
		"weizhi"	:	"/d/wuliang/road4",]),  
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/wuxi/road15",]),  
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/xiangyang/walls3",]),  
	([	"chinese"	:	"���޺�",
		"weizhi"	:	"/d/xingxiu/shidao",]),  
	([	"chinese"	:	"ѩ��",
		"weizhi"	:	"/d/xuedao/shandong2",]),  
	([	"chinese"	:	"ѩɽ������",
		"weizhi"	:	"/d/xueshan/zoulang3",]),  
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/yanziwu/qiushuan",]),
	([	"chinese"	:	"Ȫ��",
		"weizhi"	:	"/d/quanzhou/jiangjunfu1",]),
	([	"chinese"	:	"Į��",
		"weizhi"	:	"/d/mobei/hill",]),
	([	"chinese"	:	"������",
		"weizhi"	:	"/d/lingxiao/laolang",]),
	([	"chinese"	:	"�ؽ�",
		"weizhi"	:	"/d/huijiang/xingtang",]),		
});

void init()
{
	add_action("do_jie", ({"xian","jie"}));
}

int do_jie(string arg)
{
	object me, ob;
	mapping weizhis, target;
//	string  weishis;
	int exp, position;

	if(!arg) return 0;
	me = this_player();
	ob = this_object(); 
	exp=(int)me->query("combat_exp"); 
	weizhis = wheres[random(sizeof(wheres))];
//	weishis = quest[random(sizeof(wheres))];

	if(arg != "wenshu" && arg != "wen") return 0;

	if(me->query_condition("dali_xuncheng") ||
		me->query_condition("gb_busy") ||
		me->query_condition("xx_task") ||
		me->query_condition("gb_songxin"))
		return notify_fail("��������æ�������������أ�\n");
	if(me->query_condition("guanfu_task"))
		return notify_fail("���Ѿ��ҹ����ˣ��ѵ��������ˣ���\n");
	if(me->query_temp("guanfu_task") || present("wenshu", me))
		return notify_fail("�����ϻ������飬����ͨ��(kan wenshu)����ѯ��\n");
	if(me->query_condition("guanfu_busy"))
		return notify_fail("�㷢�������Ѿ����˽ҹ��ˣ�������Ҫ��һ���ˣ�\n");
	if(exp<50000)
		return notify_fail("��������֣���Ȼ�������������ɷ�Ļ�������������Լ�����㹦�򣬻������˰ɡ�\n"); 
	if(exp>=3500000) position=5;
	else if(exp>=2000000) position=4;
	else if(exp>=1000000) position=3;
	else if(exp>=250000) position=2;
	else position=1;
//	target = quest[random(sizeof(quest))];
	target = quest[position-1][random(sizeof(quest[position-1]))]; 
//	while (sizeof(filter_array(children(target["where"]),(: clonep :))) > 0)
//	target = quest[position-1][random(sizeof(quest[position-1]))];
	
	if(exp>=380000)
	{
		tell_room(this_object(), HIY + me->name() +"�ƿ�Χ�۵����ˣ��ߵ���ǰ��΢΢�����۾�������Ƴ��һ�۸�ʾ�����ֽ������������˻��С�\n"NOR, ({ me }));
		write(HIY"���ƿ�Χ�۵����ˣ��ߵ���ǰ��΢΢�����۾�������Ƴ��һ�۸�ʾ�����ֽ������������˻��С�\n"NOR);
	}
	if(exp<=120000)
	{
		tell_room(this_object(), HIY + me->name() +"׳��׳���������ο����ˣ�������ǰ�������˿�����������һ�½��ŵ����飬���¿��˿������İ��������������\n"NOR, ({ me }));
		write(HIY"��׳��׳���������ο����ˣ�������ǰ�������˿�����������һ�½��ŵ����飬���¿��˿������İ��������������\n"NOR);
	}
	if(exp>120000 && exp<380000)
	{
		tell_room(this_object(), HIY + me->name() +"�ֿ�����������ǰ��Ŀ�⵭����ɨ���˼��۸�ʾ�����΢΢һ�̣���̬����İ��������������\n"NOR, ({me}));
		write(HIY"��ֿ�����������ǰ��Ŀ�⵭����ɨ���˼��۸�ʾ�����΢΢һ�̣���̬����İ��������������\n"NOR);
	}
	me->set_temp("mark/gkill1",1);
	me->set_temp("guanfu_target", target["id"]);
	me->set_temp("guanfu_targetnm", target["name"]);
	me->set_temp("path_rooms", target["where"]);
	me->set_temp("gstart_rooms", weizhis["weizhi"]);
	me->set_temp("ch_weizhi", weizhis["chinese"]);
	new(__DIR__"task1/wenshu")->move(me);
//	me->move(me->query_temp("start_rooms"));
	ob = new(me->query_temp("path_rooms"));  
//	ob->move(__DIR__"xiaosquare");
	ob->move(me->query_temp("gstart_rooms"));
  ob->random_move();
  ob->random_move();
  ob->random_move();  // �ӵ�һ��Ѷ� �Ǻ� ��Ӧ�Ѽ������
        
	ob->set("owner",me->query("id"));
	me->apply_condition("guanfu_task", me->set_temp("guanfu_time", random(70)+20));
//	me->apply_condition("guanfu_busy", random(10)+5);
	me->apply_condition("guanfu_busy", random(3)+1);
	
	return 1;
}

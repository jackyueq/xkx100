// Room: /d/xingxiu/cangku.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	object fen1,fen2,fen3,fen4;
	
	set("short", "������");
	set("long", @LONG
����ԭ����һ������ɽ���ϵ���Ȼ�ܶ������������ϳ��Ĵ��ش���
�����濴ֻ��һ������ʯɽ�ϵ���ͨ��Ȼʯ����Ȼ��ص����ض��Ҷ���
����ʮ�ָ�������ɵ��ӽ�����������һ�����ѵĴ��ؿ⡣
LONG );
	set("exits", ([
	    "out" : __DIR__"xxroad5",
	]));
	set("objects", ([
		__DIR__"obj/yanwu" : 1,
		__DIR__"obj/hulu" : 2,
		"/clone/medicine/poison/menghanyao" : 1,
		"/clone/medicine/nostrum/qingxinsan" : 1,
		"/clone/book/dujing_1"  : 1
	]));

	set("coor/x", -50900);
	set("coor/y", 20120);
	set("coor/z", 30);
	setup();
	seteuid(getuid());
	fen1 = new("/clone/medicine/poison/duchongfen");
	fen2 = new("/clone/medicine/poison/bingpofen");
	fen3 = new("/clone/medicine/poison/honglinfen");
	fen4 = new("/clone/medicine/poison/yinlinfen");
	if (fen1->violate_unique()) destruct(fen1);
	else fen1->move(this_object());
	if (fen2->violate_unique()) destruct(fen2);
	else fen2->move(this_object());
	if (fen3->violate_unique()) destruct(fen3);
	else fen3->move(this_object());
	if (fen4->violate_unique()) destruct(fen4);
	else fen4->move(this_object());
	replace_program(ROOM);
}

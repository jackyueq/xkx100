// Room: /yangzhou/yongdao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��");
	set("long",@LONG
�������������۱����������ؼ�������ͨ�����°���������
ͨ�����˾ɹݡ����������������Ʊ����������̨���������Ӳ��죬
��Ϊ���꣬��Ϊ���ꡣ
    ���۱���ǰƽ̨�����а���Űأ����а�����������Թ���ׯ
�ϡ�
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"east"  : __DIR__"pingyuanlou",
		"west"  : __DIR__"pingshantang",
		"north" : __DIR__"daxiongbaodian",
		"south" : __DIR__"tianwangdian",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 160);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
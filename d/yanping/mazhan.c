// /d/yanping/mazhan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short","��վ");
	set("long",@LONG
�����վֻΪ��͢���Ĵ��ݺ͹�Ա���ͣ����ϰ��պͽ�������ȴˡ
���Ӵ��ˡ����ԣ���Ȼ����Ҳ�з�ʳ����ȴֻ�иɰ���ķݡ��ɴ�����
�ϣ���ͨ�����ݵĹٵ�������������������ֱ����ԭ���ݣ����߶ɹ�
���ţ�������ƽ�����ˡ�
LONG);
	set("outdoors", "yanping");
	set("no_fight", "1");
	set("no_beg", "1");
	set("exits", ([
		"north" : __DIR__"majiu",
		"south" : __DIR__"guandao3",
		"westdown"  : __DIR__"fuqiao1",
	]));
	set("objects", ([
		__DIR__"npc/yibing": 1,
	]));
	set("coor/x", 1550);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

//TORJQ1.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������ͨ�������Ĵ������·��������ſ���ʮ�˲�����С���
������������������г������磬��ģ��Ϊ��ΰ�ġ��������˲ű�����
�����ػ�������Χ�����������������б����ͻ��ߵĴ��졣
LONG );
	set("exits", ([
		"northeast" : __DIR__"torjq2",
		"southwest" : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 840);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
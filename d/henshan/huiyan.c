//Room: /d/henshan/huiyang.c
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
�����Ǻ�������¥���Ǳ������ľ�¥��������ʱ�Ѿ�ʮ��æµ��
��¥����ȴ�е�������һ�������ʮ�İ��º��ӣ������������������
����һ�ѿ쵶���Ա�ȴ����һ��С��ã������Ǽ����֮ɫ����òȴʮ
��������
LONG );
	set("exits", ([
		"down" : __DIR__"shop",
	]));
	set("objects", ([
		__DIR__"npc/tian" : 1,
		CLASS_D("hengshan")+"/lin" : 1,
	]));
//	set("no_clean_up", 0);

	set("coor/x", -400);
	set("coor/y", -1210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

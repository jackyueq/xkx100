// pine_road.c ���ִ��
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
������ɽ�������е�һ����·�ϣ���ʱ�е�ʿ�����˿��ź�����
ľ�����Ծ�������������ɽ��·��������ï�ܵ������֣����з�ľ��ϣ�
����д����������������꡹���졣
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"eastdown" : __DIR__"jiejianyan",
		"west"     : __DIR__"xuanyuegate",
		"north"    : __DIR__"pine_road1",
		"south"    : __DIR__"pine_road2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


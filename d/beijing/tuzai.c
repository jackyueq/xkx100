inherit ROOM;

void create()
{
	set("short", "���׳�");
	set("long", @LONG
���������׳��������������������ζ��ż��һ���ȷ紵������ʱ
һ�ɳ���Ϯ����ֱѬ������Ż��һ������������������ָ���Ż����ɱ
��ȥë������Ǿ����������׳�����˵�������е����ⶼ�Ǵ�������
ȥ�ġ�
LONG );
	set("exits", ([
		"east" : __DIR__"nandaj2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/lilishi": 1,
		__DIR__"npc/huoji1": 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

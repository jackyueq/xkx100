// Room: /d/yanping/yuandong.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��Գ��");
	set("long", @LONG
��Գ��λ�ھŷ����������ɣ��붴������ָ����Χ�������ܣ�
������գ�Ψ����͹��ɽ�´�����Զ���ܿ������ഫ�˶��������а�Գ
��û���紵���죬������ɽ�½�̶�������ˡ������İ˾�֮һ�ġ�Գ
����硱�ˡ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"shuyuan",
		"northeast" : __DIR__"xita",
	]));
	set("objects", ([
		__DIR__"npc/yuan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

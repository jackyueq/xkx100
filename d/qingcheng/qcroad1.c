// Room: /qingcheng/qcroad1.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
��������ʯ����ϡ�������ϡ������ֺ���Ƭ����Ұ��һ����
СϪ��·ƽ�У�Ϫ���峺���ף�ˮ��������
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"south" : "/d/chengdu/fuheqiaon",
		"west"  : __DIR__"qcroad2",
	]));
        set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

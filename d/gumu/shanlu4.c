// shanlu4.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ·��������ɽ������ϣ�ɽ·����ʯ������ֻ����һ�˵�
�������Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£�������������
�۵ף���ʱ���˺�����������Ҫ��Хһ���������º����ϸ���һ��ɽ·��
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"westup"   : __DIR__"shanlu3",
		"eastdown" : __DIR__"shanlu5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 120);
	set("coor/z", 160);
	setup();
	replace_program(ROOM);
}

// shanlu6.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����ɽ·��������ɽ������ϣ�ɽ·����ʯ������ֻ����һ�˵�
�������Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£�������������
�۵ף���ʱ���˺�����������Ҫ��Хһ���������ºͱ��ϸ���һ��ɽ·��
�������ǰ���̶��
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northup"   : __DIR__"shanlu5",
		"eastdown"  : "/d/quanzhen/shanlu13",
		"southdown" : __DIR__"baimatang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3190);
	set("coor/y", 110);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

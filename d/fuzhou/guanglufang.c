// Room: /d/fuzhou/guanglufang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "��»��");
	set("long", @LONG
��������Ԫ��(1068��)�Թ�»�������θ���֪�ݵĳ�ʦ�ϣ�����
����ķ�������������������һ�����ʯ�����ʯ��ʫ���ʱ���Ϊ����
»��̨�������˷�Ҳ����Ϊ��»������ʦ�������ġ���»��̨���ĸ�׭
��ʯ�̽��д档
LONG );
	set("exits", ([
		"east" : __DIR__"nanhoujie5",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1833);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

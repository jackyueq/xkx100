// Room: /d/fuzhou/jibixiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�׺������������֣��֮��״Ԫ�½�����ʱ��������ǰ�����Ƕ�
����������ˣ��Ըп��Ķ����ܣ���ơ��������������г��������
Ϊ���������ȡ�������⡢�Ӿ�����֮�⡣
LONG );
	set("exits", ([
		"west" : __DIR__"nanhoujie7",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6370);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

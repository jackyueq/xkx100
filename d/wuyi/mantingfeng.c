// Room: /d/wuyi/mantingfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�ͤ��");
	set("long", @LONG
�����山����ͤ�壬�׳�����壬Ϊ�ɼ�����֮�����˷嵤ϼ��
�Σ����ɻ��أ�����һ���޴�Ĵ�����ɽ�İ�ڡ��ͤ�����֣�Ϊ����
��˼ѧ���顣ɽ������ƽ̹������һ��״���㶦�ľ�ʯ����������̳��
�ഫ���ľ��ͻ�̫�ѡ�κ������ڴ����ͤ������ˡ����ͤ��֮����
�˶�����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"huanguyan",
		"southdown" : __DIR__"path3",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 1390);
	set("coor/y", -4970);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}


// Room: /d/quanzhou/jietang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¶��̳");
	set("long", @LONG
�Ӵ����ų������������ܰ˽��ܼ�ʽ�Ľ�̳���Ƿ��ͽ�ܽ����
֮����̳���弶����߲��з�ľ���¬������������������ͼ�Ĳ
��𡢰����ӷ�ǧ��ǧ�۹�����ȡ�̳�����С�����𧡹�͡������
������������λ��ʮ����������ׯ�ϡ�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south"   : __DIR__"yuetai",
		"northup" : __DIR__"cangjingge",
	]));
	set("coor/x", 1830);
	set("coor/y", -6480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

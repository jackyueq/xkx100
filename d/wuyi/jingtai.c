// Room: /d/wuyi/jingtai.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��̨");
	set("long", @LONG
�����������֮�ϣ���ڵ��ұ��ϴ��顰��̨�����֣����Ǿ�����
��Ů������ԡ����ױ�ľ�̨�ˡ���̨����Ů����ԣ�ԶԶ��ȥ��������
Ů�پ��廨����̬��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"yunvfeng",
		"south"     : __DIR__"huxiaoyan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


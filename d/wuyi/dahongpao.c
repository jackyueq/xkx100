// Room: /d/wuyi/dahongpao.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������̶��ɱ�ľ��������Ĺ��޵ء�Ͽ������Ϊ�������ͻ
أ�ķ��ң�������������ڿ����ɣ��ʳơ�����񽡱������۲����͸�
ֲ�ھ������ұ��ϡ��Ҷ�������ˮ���䣬����������������⼸�꿵
���ʵ����ͺ������ҵġ�����֮������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"      : __DIR__"path11",
		"northwest"  : __DIR__"path10",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4950);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


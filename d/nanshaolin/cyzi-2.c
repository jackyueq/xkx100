// Room: /d/nanshaolin/cyzi-2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��԰��");
	set("long", @LONG
�����������µĲ�԰�ӣ���Բ��������Ķ�أ�����������߲ˣ���
��������������ġ����ڷ����ɮ�ˣ�Ҳ�������������Щ���񣬽�
�صĿ��ۣ����������԰������ʮ����ɮ��æµ�ĸ����ţ������м���
���Ͼ�Ȼ��������
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"  : __DIR__"cyzi-3",
		"north" : __DIR__"cyzi-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1870);
	set("coor/y", -6330);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


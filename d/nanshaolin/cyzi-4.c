// Room: /d/nanshaolin/cyzi-4
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
		"west"  : __DIR__"cyzi-1",
		"south" : __DIR__"cyzi-3",
	]));
	set("coor/x", 1880);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


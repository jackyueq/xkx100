// Room: /d/yueyang/yaopu.c
// Last Modifyed by Winder on Dec. 4 2001
inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ����̨������һ����
ҩ����������ĵļ��ٸ�С��������Ҳ�������ˡ���̨��վ��һ��С
��ƣ�һ˫��������۾���ʱɨ�����������
    ��������һ������(zhaopai)��
LONG );
	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"beijie",
	]));
	set("coor/x", -1420);
	set("coor/y", -2260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /yangzhou/tianningshuju.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�������");
	set("long",@LONG
����ר���з��и����ֻ����鼮�̱������л��в������ѵ�һ����
�䱾���������ϰ岻�ƾ�Ӫ�����ϵط�����ƫƧ������ÿ�����飬����
����û�ж��٣����ڹ�����Щ���㣬ֻ���ϰ�������һ���޾���ɵ���
�ţ��������(shelf) ���߰������һЩ���ᣬ�߶���������һ������
���µĸо���
LONG );
	set("exits", ([
		"southeast"  : __DIR__"tianningxiang",
	]));
	set("objects", ([
		__DIR__"npc/bookboss" : 1,
	]));
	set("item_desc", ([
		"shelf"  : "����϶������飬��Щ�Ѿ������������á�\n",
	]));
	set("coor/x", 30);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/lingxiao/yaodian.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "�ش���");
	set("long", @LONG 
�������������ҽ��������Ĵ���������Ļش��ӣ�һ�������
�ŵ�һ�ɴ̱ǵ�ҩζ��ֻ�����а����˴��СС��������ҩ��һ����
���԰׵������������ԣ�������һ�˰������Աߵ�ǽ������һ��������
(tiaofu)�����Ǳ�������κ��˵Ĳ����͵ġ�
LONG );
	set("no_fight",1);
	set("item_desc", ([
		"tiaofu" : "��٢��������ȵ������\n",
	]));
	set("objects", ([
		__DIR__"npc/daifu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"iceroad2",
	]));
	set("coor/x", -30990);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


// Room: /d/lingxiao/walle2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ");
	set("long", @LONG 
ѩ��ƮƮ��վ�������֮�����������֮���ơ���˼�����ۻʣ�Ϊ
����ͼ��ҵ��ÿÿ����Զ������ɽ��������ȴ������ս������ɽ���죬
ƫ�����˷صء�����˾����������������������ԣ��������޶��ӱ߹ǣ�
���Ǵ��������ˡ���Ϊһ��֮����������֮�ˣ��Ž�ͬ�ӣ�
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east" : __DIR__"walle3",
		"west" : __DIR__"walle1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30980);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}


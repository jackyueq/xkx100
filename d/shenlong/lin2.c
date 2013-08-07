// /d/shenlong/lin2.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;
string* npcs = ({
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/jinshe",
	__DIR__"npc/qingshe",
	__DIR__"npc/fushe",
});
 
void create()
{
	set("short", "��ľ��");
	set("long",@LONG
������Ƭ��ľ�֡���Χ��������֣����������һ��Ī���Ŀ־��
�����㡣���˲�Զ����Ϳ��Կ��ü�ǰ��Ŀյ��ˡ�
LONG);
	set("exits", ([
		"northdown" : __DIR__"kongdi",
		"southup"   : __DIR__"lin1",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 1+random(2),
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]) );
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

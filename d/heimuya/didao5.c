// Room: /d/heimuya/didao5.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ص�");
	set("long", @LONG
�������棬�㲻���뵽���ƺ���ÿ�����䶼��������ɱ������е�
���˽��ˣ�Խ��Խ���ˡ�
LONG );
	set("exits",([
		"east" : __DIR__"didao3",
		"west" : __DIR__"didao3",
		"north" : __DIR__"didao2",
		"south" : __DIR__"didao1",
	]));
	set("objects",([
		__DIR__"npc/snake" : 4,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
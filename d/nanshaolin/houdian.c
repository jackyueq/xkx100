// Room: /d/nanshaolin/houdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
����ģ�������߶���ˮĥʯ�ڣ��ο��ŷ��Ÿ�λ���ʹ�µ�Ф
�񼰻������������һ�ڴ�ˮ��(gang)���Լ�����ɮ������ڿʼ���
������֮�衣ÿ�ն���רְɮ�´���ǰ���ľ��е�ˮ���ˡ�
LONG 
);
	set("exits", ([
		"west"  : __DIR__ "hguangc4",
		"east"  : __DIR__ "hguangc5",
		"north" : __DIR__ "taijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangjie" : 1,
		__DIR__"npc/zjseng" : 1,
	]));
	set("item_desc", ([
		"gang" : "����һ��ͭ�ƵĴ�ף������ʢ�¼���Ͱˮ��\n",
	]));
	set("resource/water",1); 
	set("coor/x", 1820);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}	   

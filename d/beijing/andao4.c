// /d/beijing/andao4.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
�ص���һƬ��ڣ������ķ���������˷���������ʲôҲ��������
ֻ���ڵص���Ϲ����ײ�������ƺ�����ԼԼ����˵������ֻһ�����û
���ˡ���ʹ����ҡ��ҡͷ���ܻ����⵽���ǲ��ǻþ����������Ѿ���·
�ˡ�
LONG );
	set("exits", ([
		"west"  : __FILE__,
		"east"  : __DIR__"andao6",
		"south" : __FILE__,
		"north" : __DIR__"andao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}

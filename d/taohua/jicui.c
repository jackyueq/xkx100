// Room: /d/taohua/jicui.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
������������֦��ɵ���ͤ��ͤ�Ϻ�����¹��¿��÷������ǡ���
��ͤ�����֣��������Ÿ�����(duilian) ��ͤ�з�����̨���Σ�ȫ�Ƕ�
��֮��õ����ˣ��¹����ֳ������ƹ⡣��֮ͤ�ಢ���������ô���
����֦����̣�ֻ������������Ĺ��������ɴ��������ޱȡ�
LONG
	);
	set("exits",([
		"north" : __DIR__"hetang",
		"east"  : __DIR__"kefang",
		"south" : __DIR__"caodi",
	]) );
	set("no_clean_up",0);
	set("outdoors","taohua");
	set("item_desc",([
		"duilian" : "
��                   ��
��                   ��
Ӱ                   ��
��                   ��
��                   ��
��                   ��
��                   ��\n
"
	]) );
	set("objects",([
		CLASS_D("taohua")+"/huang" : 1,
	]) ); 

	set("coor/x", 9010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
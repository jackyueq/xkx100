// Room: /d/taohua/hill1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ������һת���۶��򱱾Ϳɵִ�ɽ������Զ������һƬ�һ�����
�дУ���һ�����Զ���󺣣���Ŀ���콻�Ӵ����ƺ���Щ��Ӱ��������
���ǻþ���
LONG
	);
	set("exits", ([ 
		"westdown" : __DIR__"hill",
		"northup" : __DIR__"hill2",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 8510);
	set("coor/y", -4690);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
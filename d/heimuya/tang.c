// Room: /d/heimuya/tang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;			   
void create()
{
	set("short", "������");
	set("long",@LONG
�����Ǻ�ľ�µĵڶ����ð׻��õ������ҡ�������ש�̵ء�������
һ����(box1).
LONG );		  
	set("exits", ([	
		"west"  : __DIR__"qing",
	]));
	set("item_desc", ([
		"box1": "���Ǹ������Ƶĺ��ӣ������ѱ��˴򿪣��տ���Ҳ ��\n",
       	]) );
	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 3990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

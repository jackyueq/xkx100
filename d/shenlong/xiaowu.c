// /d/shenlong/xiaowu.c
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ROOM;
string* books = ({
	"/clone/book/book-bamboo",
	"/clone/book/book-paper",
	"/clone/book/book-stone",
	"/clone/book/book-iron",
//	"/d/shenlong/obj/shoufa",
//	"/d/shenlong/obj/bufa",
});


void create()
{
	set("short", "С��");
	set("long", @LONG
һ��С�ݣ�ֻ��ǽ�Ϲ���������������ֻ��������Ҳ������ƽʱ
�ѵ�һ���ĸ��ָ������鼮��һ����òӢ���������ʿ������һ���ֻ�
����̾����
LONG );

	set("exits", ([
		"south" : __DIR__"caodi",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/lu": 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("outdoors", "shenlong");
	set("coor/x", 4000);
	set("coor/y", 3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}


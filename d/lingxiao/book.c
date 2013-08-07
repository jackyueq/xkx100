// Room: /d/lingxiao/book.c
// Last Modified by winder on Jul. 15 2001

inherit ROOM; 
string* books = ({
	BOOK_DIR+"book-bamboo",
	BOOK_DIR+"book-silk",
	BOOK_DIR+"book-stone",
	BOOK_DIR+"book-iron",
});
void create()
{
	set("short","�鷿");
	set("long",@LONG
�����ǰ����ڵ��鷿��һ��֮�ڣ������˸����鼮����������Ȼ��
���Դ󣬵�˵��ѧ�ʣ�ȴ����Ҳ�Ǳ���ʫ�飬ѧ���峵���������ܣ�
���СС������ʮ�����ɡ������ڵ���ͯ������Ϊ������
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east"   : __DIR__"weideju",   
		"south"  : __DIR__"bridge",
	]));
	set("objects", ([  
		__DIR__"npc/su" : 1,  
		BOOK_DIR+"feixue-book" : 1,  
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup(); 
	replace_program(ROOM);
}


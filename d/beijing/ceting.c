inherit ROOM;

string* books = ({
	BOOK_DIR"yljing",
	BOOK_DIR"yljing1",
	BOOK_DIR"yljing2",
	BOOK_DIR"book-bamboo",
	BOOK_DIR"book-silk",
	BOOK_DIR"book-stone",
	BOOK_DIR"book-iron",
	BOOK_DIR"quanpu",
	BOOK_DIR"dujing_1",
});

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǲ�������ǽ��һ����ܣ������˸���ȭ�ס��鼮��ǽ����һ
��ľ������ػ��ܶ����½��ϳ�����������顢��Ϣ��
LONG );
	set("exits", ([
		"west" : __DIR__"dating",
	]));
        set("sleep_room", 1);   
	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}

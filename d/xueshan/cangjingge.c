// cangjingge.c ѩɽ�ؾ���

inherit ROOM;

string* books = ({
        "/clone/book/mizong_book",
        "/clone/book/skin",
	"/clone/book/book-bamboo",
        "/clone/book/book-silk",
	"/clone/book/book-stone",
	"/clone/book/book-iron",
});
void create()
{
        set("short", "ѩɽ�ؾ���");
	set("long", @LONG
������ѩɽ�µĲؾ��ң���ǽ��һ����ܣ������˸���ȭ�ס��鼮��
����ǵ����������Ħ�Ƿ���ķ𾭺ʹ�������ȡ������ѧ�伮��
LONG );
	set("exits", ([
                "southeast" : __DIR__"dating",
	]));

	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
                CLASS_D("xueshan")+"/daerba" : 1,
	]));
//        set("no_clean_up", 0);
	set("coor/x", -70010);
	set("coor/y", -19880);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}

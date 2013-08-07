// Room: /d/kunlun/shanbi.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һƬ���͵�ɽ�ڣ�ȫΪ��Ϊ��Ӳ����ʯ��������ţ���΢��С
�ľͻỬ������ɽ���ϻ����������֣������޼��񾭴���������������
һƬ���죬����������һɽ����
LONG	);
	set("outdoors", "hongmei");
	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"cuigu",
		"eastdown" : __DIR__"shangou",
	]));
	set("count" ,1);
	set("no_clean_up", 0);
	set("coor/x", -99000);
	set("coor/y", 20050);
	set("coor/z", 50);
	setup();
}
void init()
{
	add_action("do_dig","dig");
}
int do_dig()
{
	object book1, book2, me = this_player();
	int books=0;
	
	if (query("count") >0 )
	{
		add("count", -1);
		book1 = new(BOOK_DIR+"medicine6");
		if (book1->violate_unique()) destruct(book1);
		else {
			books = 1;
		  book1->move(this_object());
		}
		book2 = new(BOOK_DIR+"medicine7");
		if (book2->violate_unique()) destruct(book2);
		else {
			books ++;
  		book2->move(this_object());
  	}
		if ( books > 0 )
		{
			message_vision("$N����һ�ᣬ�ڳ���һ���Ͳ������򿪰�����......��\n",me);
	    return 1;
	  }
	}
	message_vision("$N����һ�ᣬ���ֺ���ʲôҲû�У������޺޵����˿���ĭ��\n",me);
	return 1;
}

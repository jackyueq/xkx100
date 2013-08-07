//Room: /d/city/shuyuan2.c

string look_shelf();

#define STORY_TOC "/doc/legend/toc"
#define STORY_DIR "/doc/legend/"
inherit ROOM;

void create()
{
	set("short", "��ѩ��");
	set("long", @LONG
�����������������Ͼʱϲ�������ĵط������ﴰ��������һ����
Ⱦ�����ϵ����(shelf) ���������е������ǵ���ѡ����¼�������е�
�����������������������ֺ����ŵĴ�˵����Ȼ��Щ�����Ѿ���ң
Զ��ȴ����ĥ��������Ķ�(read)����Щ���ϵĹ��¡�¥�������Ժ��
�ղ��н�ӹ��ʦ����Ҫ��Ʒ��
LONG);
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"shuyuan1",
		"up"   : __DIR__"shuyuan3",
	]));
	set("objects", ([
		__DIR__"obj/wizboard" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_read", "read");
}

string look_shelf()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_read(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(STORY_DIR + arg) <= 0)
		return notify_fail("����û���Ȿ�顣\n");

	log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(STORY_DIR + arg));
	return 1;
}

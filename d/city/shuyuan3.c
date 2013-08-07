//Room: /d/city/shuyuan3.c 
string look_table();

#define STORY_TOC "/doc/book/toc"
#define STORY_DIR "/doc/book/"
inherit ROOM;

void create()
{
	set("short", "���Ժ");
	set("long", @LONG
����һ�����������Ĵ����ӣ�����һ�Ŵ����� (table)����������
�����顣�����ղ���������ʦ��ӹ��������Ҫ��Ʒ�����о��Ķ��ǡ���
Լ����Ĺ��£��ɴ�ʦ����������渵�������������Ĵ���ʱ����
�������ߡ���������ζ�Լ������Ľ�����������Щ�������ĸ��ܣ���
�Լ������ĵ�������ӡ֤��ʦ���ֱʣ���д���Լ����Ͻ���֮·��ҹ��
�˾�ʱ���������շת���ߣ��������� (fan)��Щ�顣¥���Ƿ�ѩ�ã�
�ղ�������������ҵ���Ʒ��
LONG);
	set("item_desc", ([
	    "table" : (: look_table :),
	]));
	set("exits", ([
	    "down" : __DIR__"shuyuan2",
	]));
	set("objects", ([
	    __DIR__"player/aiwoaini" : 1,
	    __DIR__"player/autodami" : 1,
	    __DIR__"player/august" : 1,
	    __DIR__"player/batwing" : 1,
	    __DIR__"player/karice" : 1,
	    __DIR__"player/piaoxue" : 1,
	    __DIR__"player/qianqiu" : 1,
	    __DIR__"player/tiji" : 1,
	    __DIR__"player/welcome" : 1,
	    __DIR__"player/wpp" : 1,
	    __DIR__"player/wrong" : 1,
	    __DIR__"player/yzjiang" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", 20);
	set("coor/y", 32);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_fan", "fan");
}

string look_table()
{
	this_player()->start_more(read_file(STORY_TOC));
	return "\n";
}

int do_fan(string arg)
{
	object me=this_player();
	if (arg == "" || file_size(STORY_DIR + arg) <= 0)
		return notify_fail("����û���Ȿ�顣\n");

	log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
	me->start_more(read_file(STORY_DIR + arg));
	return 1;
}

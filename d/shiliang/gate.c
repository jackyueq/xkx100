// Feb. 6, 1999 by Winder
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_climb(string arg);
void create()
{
    set("short", "��լ����");
    set("long", @LONG
�����������ʯ���¼ҵĴ��ţ��ſ�������ʯʨ��������
�������Ž����ţ����ϵ�ͭ��ȴ���ô��ۡ�Χǽ�ܸߣ�������
д�������̽�Ĵ��֡��¸�������Ȼ���Ȳ������ŵ��Ա���һ
��������(tree),��վ������������졣
LONG
    );
	set("no_clean_up", 0);
	set("outdoors","shiliang");
	set("exits", ([
		"south" : __DIR__"road1",
	]));
	set("item_desc", ([
	"tree": "����һ���ϰ������������֦Ҷ��Ȼʮ��ïʢ��������������ȥ�ġ�\n"
	]) );
	set("coor/x", 1610);
	set("coor/y", -1970);
	set("coor/z", 10);
	setup();
}
void init()
{
    object book, me;
    me = this_player();
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="tree" ) {
        write("��Ҫ����������\n");
        return 1;
    }
    message_vision(
    "$N�ڹ���ǰ��������˿������͵�Ծ��������\n", this_player());
        
    if (n>=80) {
        message_vision("ֻ��$N�������֦��һ�㣬����Ծ����ǽ������ȻƮ��Ժ�С�\n", this_player());
        this_player()->move(__DIR__"yuanzi");
    }
    else if (n>=50) {
        message_vision(
        "ֻ��$N˫��������һ�ʣ���ǿ����Χǽ������Ժ�С�\n", this_player());
        this_player()->move(__DIR__"yuanzi");
    }
    else {
        message_vision(
        "$N�߸�Ծ�𣬿ɻ���һ����أ��������Ṧ�����á�\n", this_player());
     }
    return 1;
}
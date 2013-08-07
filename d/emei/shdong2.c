inherit ROOM;
int do_search();
void end(object);
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ⶴ����������ǰһ������ϸ��ʱ��������һ����
�ⶴ��Ҫ��ܶ�Ķ�Ѩ���ı��Ϲ�������Ǿ��壬������
�����ζ����Ҫʹ����Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"shdong1",
        ]));
        set("objects",([
            __DIR__"obj/liuhuang" : 3,
        ]));
	set("coor/x", -6190);
	set("coor/y", -1150);
	set("coor/z", 100);
	setup();
}
void init()
{
        add_action("do_search","search");
}
int do_search()
{
        object me = this_player();
        object ob ;
        int jing;
        if( me->is_busy() )
                return notify_fail("����һ��������û������ء�\n");
        jing=me->query("jing");
        if(jing<30)
                return notify_fail("���޷����о����鿴��\n");
        message_vision("$N��ʼ�鿴�����ʯ�ڣ�ϣ�����ҵ�һ����ǡ�\n",me);
        me->start_busy(2);
        me->set("jing", jing-20);
        call_out("end",3,me);
        return 1;
}
void end(object me)
{
        object ob;
        if(random(2)==0)
                message_vision("$N���˸����������ʲô��û���ҵ���\n",me);
        else
        {
                ob=new(__DIR__"npc/obj/liuhuang");
                ob->move(me);
                message_vision("$N�ҵ���һ����ǣ��������ϡ�\n",me);
        }
 }
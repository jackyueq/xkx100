// Feb. 6, 1999 by Winder
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_break(string arg);
int do_ba(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������һ��ʯ���ڣ�ͻȻ����ǽ���и�������ʯ��(shibi)��
��ȥ���Ǻܽ�ʵ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"jinshedong",
        ]));
       set("item_desc",([
            "����" : "����һ������ֵĽ�������֪����û�н���������ȥ������\n",
            "shibi" : "Ҳ������Դ�(break)����\n",
             ]));
	set("jiancount",1);
        set("no_clean_up",0);
        set("coor/x", 1590);
	set("coor/y", -1980);
	set("coor/z", 10);
	setup();
}
void init()
{
    add_action("do_break", "break");
    add_action("do_ba", "ba");
}
int do_break(string arg)
{
    int n;
    n = this_player()->query("neili");
    if( !arg || arg!="shibi" ) {
        write("�㲻�ǳ��ˣ���ô��������\n");
        return 1;
    }
    message_vision(
    "$N�ߵ�ʯ��ǰ�����һ����һ�ƻ���ȥ��\n", this_player());
        
    if (n>=1000) {
        message_vision(
        "$Nֻ��һ�����죬$N��ʯ����һ���󶴣�\n", this_player());
        set("exits/north", __DIR__"shandao1");
        this_player()->set("neili",n-1000);
        remove_call_out("close");
        call_out("close", 10, this_object());
    }
    else {
        message_vision(
        "$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
    }
    return 1;
}
void close(object room)
{
    message("vision","ʯ�ں�Ȼ������صú����ˡ�\n", room);
    room->delete("exits/north");
}
int do_ba(string arg)
{        object jian;
         object me;
         me = this_player();
         if( !arg || arg=="" ) {
message_vision("�����ʲô��\n", me);
return 1;
}
if( arg=="����"||arg=="jian" ){
        if(query("jiancount") < 1)
        return notify_fail("�������ȥ���ǽ���������ȴ���˸��գ������ӽ��Ѿ�����ȡ���ˡ�\n");
        if( (int)me->query("str") < 28 )
        return notify_fail("��ı���̫С��ʹ�����̵ľ���������Ȼ��˿������\n");
        if( (int)me->query("neili") < 2000 )
        return notify_fail("������������ˣ��β���������\n");
        jian = new("/clone/weapon/treasure/jinshejian");
        if (jian->volate_unique()) 
        {
        	destruct(jian);
        return notify_fail("�������ȥ���ǽ���������ȴ���˸��գ������ӽ��Ѿ�����ȡ���ˡ�\n");
        }
	message_vision(
        HIW "$N��������Ĭ���������������⣬һʱ��·��붨�ˡ�\n"+
            "ͻȻ��$N���о����ʢ������ȫ���Ǳ�����͵ذ����ǽ�\n"+
            "����ɲ�Ǽ䣬����Ϊ֮��ɫ������Ϊ֮������ֻ��һ����\n"+
            "�Ź����ɫ�����γ�����ʯ���зɽ�����������\n"NOR, me);
        me->add("neili", -2000);
        jian->move(me);
        add("jiancount",-1);
        return 1;
        }else
        message_vision(
        "������ʯ���ϵĽ���ֱ���.....\n", me);
	return 1;	     
}
void do_jian()
{
	set("jiancount",1);
}
int valid_leave(object me, string dir)
{
        tell_object(this_player(),WHT "ڤڤ�䣬������и����������㣺�˼���һ����֮� \n"+
                                      "����һ�������񹲲���ϡ����������һ��\n"NOR,this_player());
        return 1;
}

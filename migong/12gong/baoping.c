// by HAPP@YSZZ

inherit ROOM;
 int block_cmd(string);
void create ()
{
        set ("short", "��ʮһ����ƿ��");
        set ("long",             @LONG
 :i$$$$Wx     xoW$$$$$Wu:      xi$$$$$Wx:     :ui:
 "#*$$$$$$WW$$$*#"#$$$$$$$$WW$$$**$$$$$$$$WeW$$*#
  : ~ #$$$$$*"~     ~#$$$$$$#"~    "#$$$$$$*#"
                       ~                        ~
 :xW$$Wi      :xiW$$$Wi::       iW$$$Wu:       :u:
 !$$$$$$$Wooo$$$*#$$$$$$$$Wooo$$$$$$$$$$$iuooW$$#
     "*$$$$$$#~     "*$$$$$$$#"   ~"*$$$$$$$*"~
        ~"~            ~~"~           ~~~
            �����������Ӹ���÷���Ǹ��ƽ��������꣬��һ����������ʱ��
        ͻȻ����˹��ɵ���ӥ׽��������˹������޸�������˹�����̹���    
        ԭ�����ε���ƹ������ڹŴ���������̫����λ������������ĵ�
        һ����Ϊ�꼾�����Զ���Ϊˮƿ��

LONG);
        set("exits", ([
        "southup"    :       __DIR__"bp2sy1",
        "westdown"  :       __DIR__"mj2bp2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baoping" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if ( present("bao ping") && dir == "southup" )
        return notify_fail("����ŵ˹Ц��:�ȹ��������˵��\n");
        return ::valid_leave(me, dir);
}

 void init()
{
     add_action("block_cmd", "", 1);
 }
int block_cmd(string args)
{
string verb;
 verb = query_verb();
    if (verb == "hit") return 1;if (verb == "fight") return 1;if (verb == "touxi") return 1;if (verb == "exert roar") return 1;
   return 0;
 }

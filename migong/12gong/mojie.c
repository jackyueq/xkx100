// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "��ʮ��Ħ����");
        set ("long",             @LONG
        :W$$!
        $$$$X        :i$W
      i$$$$$$i:   xo$$$#~
   WW$$*"#$$$$$$$$$$#~          ����˹�Ķ����˶��ǰ���֮һ�������䲻������ 
  ~*#"    ~"#*$$$*"             ,��ȴ��Զ������׿Խ�������˶��ĳ������� 
            x$$$~               ��Ҳ�ӵģ���ͷ�ϳ���ɽ��Ķ�������ǣ��ϰ� 
           X$$#     : ::        ���ǳ�ë�����Σ��°���ȴ��ɽ�����̬������ 
          !$$$ :xWW$$$$$$WX:    ϲ�����֣����������Լ����Ƶ�έ�ѡ� 
         !$$$!X$$$$#"##$$$$$X
         H$$$$$$#~      !$$$$!  ��һ�Σ����������޺Ӱ������ʱ��ͻȻ������   
         M$$$$#~         !$$$M  һ����������񶼴�ʧɫ����ɸ�����̬��
         ?$$$$!          !$$$M  �����У��˶�Ҳ��æ����ˮ�б��ѣ�����춹��� 
          R$$$$          $$$$~  ����ʧ�룬���޷���ȫ���һ���� ....����ǡ�Ħ 
           $$$$$Wx::::uW$$$*!   ���������������� 
          :M$$*$$$$$$$$$$#!
           ?$$! ~~"""~~
            ~~                           
LONG);
        set("exits", ([
        "westup"    :       __DIR__"mj2bp1",
        "northdown"  :       __DIR__"rm2mj2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/mojie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("mo jie") && dir == "westup" )
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

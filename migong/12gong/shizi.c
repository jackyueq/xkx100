// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "���幬ʨ����");
        set ("long", @LONG
                ::::
           :uW$$$$$$$$Wx:
         :W$##""""#R$$$$$X
        X$?          "$$$$X
       X$?             #$$$:
       $$!              M$$
       R$8:             !$$     ��˵�к��������йصı�����λ�ϣ��֮���װ�
       ~$$$W:           !$?  (Nimean)�ȵص�һͷʨ�ӣ���һ�β����б�����
      :X$$$$$W:         MM   ��˼ɱ����
    :H$$###R$$$X:      :$!
   :$$"      ?$$W      HM
   $$!        ?$$:     $$
  !$$         !$$      $$X
   R$W:      :8$!      M$$WxX!
    #$$WuxxxW$$?        R$$$"
      "#R$$$#"           "#R
LONG);


        set("exits", ([
        "northup"    :       __DIR__"sz2sn1",
        "eastdown"  :       __DIR__"jx2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shizi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shi zi") && dir == "northup" )
        return notify_fail("��������Ц���ȹ��������˵��\n");
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

// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "���߹������");
        set ("long",
             @LONG
              :X88$8W!:
                  X8$$$R$$$H:
                 X$$R~~ ~#$$M:
  ~MWx!::::::::::M$$!     M$$X:::::::::::i8!
   H$$$$$$$$$$$$$$$$      !$$$$$$$$$$$$$$$$
  :H$##############M      ~##########M###R$!

   MHxx:x::x::X::x::x::x::x::x::x::x:::x:i8!
   !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
   H$#M##################################R$!

                ��ϣ������Ů��˾�����Ǹ��ƹ��ƶ����ƽ��
                �����϶���ɵġ���Լ��Ԫǰ���������������
                �Ͱͱ����ڽ����������������йأ���ƽ������
                ���������ƶ�֮�á�


LONG);


        set("exits", ([
        "southup"    :       __DIR__"tc2tx1",
        "westdown"  :       __DIR__"sn2tc2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianchen" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("tian chen") && dir == "southup" )
        return notify_fail("�����޵ϵ�Ц��:�ȹ��������˵��\n");
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

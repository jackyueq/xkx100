// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "�ڶ�����ţ��");
        set ("long", @LONG
   uiWW!             !WWu:
     :W$$#~             ~"*$$X
   :W$$#                   ~$$$!
   $$$!                      #$$!
  !$$#                       ~$$$
  $$$!                        $$$
  !$$W                       :$$$
   $$$W                     :W$$T  ��  ����ϣ����Ī���ǵط��ı���˹�ӣ�������
   ~#$$$W: ::WWWWWWWWWX  :uW$$$#~ ��˹��λ�����Ĺ�����������һ�죬��������
     ?$$$$$$$$*#*#*#*$$$$$$$$#~ ��Ů�ǵ�Ұ��ժ������ˣ��ͻȻ����һֻ��ѩ����
       ~"*$$$$~      #$$$*#"~ ��׵�ţ���Լ�������۹�������������ʵ��ֻţ
          W$$~        #$$~: ����Ľ������ɫ����˹��ġ�һ��ʼ������ȷ���һ����
         !$$R         ~$$! ����������ѱ��ţֻ���ԣ����ḧ���������ڹ�ţ�Ե�
          #$$!        W$$  �ǳ����ɶ���ѱ�����ǹ����ͷ��ĵ�����ţ���������
           #$$W :   :$$$~ Ȼ��ţ����������������������ٺ�������������ţ����
            ~$$W   :$$# ������Գ�������˹���񣬹�������֪��ţ����˹�Ļ���
             ~#$$WW$$# ���˿����ص��󣬾ͺ���˹���л��񣬻���Ϊţ����˹�ͺ�
               "###?~ �����������Ҹ������ӡ�

LONG);


        set("exits", ([
        "westup"    :       __DIR__"jn2sz1",
        "northdown"  :       __DIR__"by2jn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jinniu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("jin niu") && dir == "westup" )
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

// by HAPP@YSZZ
#include <ansi.h>
inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "���Ĺ���з��");
        set ("long", @LONG
               :XxuxuX:::
        :uWW$$$$$$$$$$$$$$$Wix:
     :U$$$$$#""~~      ~~""##$$$ix      ����֮����������Ů����
   !W$$$$$$$$$Wi:             ~~#*$W::  ���պ���׷���ɭ��֮��
  !$$*"~    ~"T$$$:                ~#8: ������Ů������һŮ��
  $$?          ~$$$          :          ��֮���൱��ŭ
 !$$            X$$    XWW$$$$$$$Wu:    �ɾ�ͷ��зȥɱ��ĸŮ����
 !$$:       :  ~8$$  !$$$?~     ~?*$W:  ����Ů��Ϊ�˱����Լ���Ů��
  ?$$X        !W$$! !$$!           #$8  �¸ҵĺ;�з�Ҷ��������
   ~T*$$WWW$$$$*!~  !$$            !$$  ��֮������ĸ�����ж�
       ~~"~!~       !$$X  :        W$$  ��СŮ�����ճ��˾�з���� ......
 !W::                ?$$Wx:     :!W$$!
  ~#$WU::             ~#*$$$WWW$$$$#~
     "#$$$Wxx::          ::W$$$$$#~
        ~"#$$$$$$$$$$$$$$$$$$#"~

LONG);


        set("exits", ([
        "eastup"    :       __DIR__"jx2sz1",
        "southdown"  :       __DIR__"sz2jx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/juxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("ju xie") && dir == "eastup" )
        return notify_fail("������˹:�ȹ��������˵��\n");
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

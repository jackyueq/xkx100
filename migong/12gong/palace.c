// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "�ƽ�ʥ��");
        set ("long",
             @LONG
     p                  p         p
    /\     p      p    /\        /\
   /__\   /\_____/\   /__\      /__\
   |. |_=_|. . . .|_=_=_=_=_=_=_|. |
   |. |. .|  ___  |. . . . . . .|. |    �ŵ������ִ����
   |. |   | |   | |             |. |
 __|__|___|_|___|_|_____________|__|__
/          /   /                      \


LONG);

  set("no_fight", 1);
  set("no_magic", 1);

        set("exits", ([
        "down"  :       __DIR__"topalace3",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
__DIR__"npc/ydn" : 1,    
        ]));
        setup();
}

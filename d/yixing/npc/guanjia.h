//Cracked by Kafei
// /d/huanghe/npc/guanjia.h
// by aln 2 / 98
#include <changle.h>
#include <ansi.h>
#include D_STORE
#include D_BIAO
#include D_GUEST
#include D_BUSINESS
//#include BANGS + "REGIONS.h"
int is_victim(object, string);


string ask_job()
{
        object me = this_player(), leader, ling, ob, *obj, dest, room;
        string myfam, *files, file, region, biaoju, ob_bang;
        int i, temp, myexp;
        mapping job;

        string *levels = ({
                "3000",
                "5000",
               "10000",
               "20000",
               "50000",
              "100000",
              "300000",
              "500000",
        });

        myfam = (string)query("party/party_name");
//        if( (string)me->query_temp("bangs/fam") != myfam )
        if( (string)me->query("party/party_name") != myfam )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";  

        if( time() < (int)me->query("bangs/asktime") + 60 )
                return RANK_D->query_rude(me) + "���Ǹ��ʹ�����";

        if( objectp(leader = me->query_leader()) ) {
                if( leader != this_object() )
                         return RANK_D->query_rude(me) + "�����˰ﻹ���Ķ�������ˣ���";
        }

        me->set("bangs/asktime", time());

        if( !(ling = present("bang ling", me)) ) {
                ling = new(BANGLING);
                ling->set("owner", me->query("id"));
                ling->set("fam", myfam);
                ling->set("combat_exp", query("combat_exp"));
                ling->move(me);
                message_vision("$N��һ" + ling->query("unit") + ling->name() + "�Ӹ�$n��\n", this_object(), me);
        }

        myexp = (int)me->query("combat_exp");
        myexp = (4 * myexp + random(2 * myexp)) / 5;

        temp = sizeof(levels);
        for( i = 0; i < temp; i++ ) 
                if( myexp < atoi(levels[i]) ) break;

        if( i >= temp )
                return "���û���ʺ���İ���";

        job = (BANGJOB + levels[i])->query_job();

        if( mapp(ling->query("job")) )
                ling->delete("job");
        ling->set("job", job);

        if( ob = present("caili", me) )
                destruct(ob);

        switch(job["type"]) {
        case "Ѱ":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return "��ȥ��" + job["name"] + "������";
                break;

        case "ɱ":
                command("nod");
                ling->set("job/max", atoi(levels[i]));
                return "��ȥ��" + job["area"] + "��" + job["name"] + "ɱ�ˡ�";
                break;

        case "̯��":
                command("nod");
                job = info_store[random(sizeof(info_store))];
                ling->set("job/name", job["name"]);
                ling->set("job/boss", job["boss"]);
                ling->set("job/place", job["place"]);
                return  job["name"] + "����»�û�н�̯�ѣ���ȥҪ����";
                break;

        case "����":
                obj = filter_array(children(BIAOTOU), (: clonep :));
                if( sizeof(obj) < 10 ) {
                        ob = new(BIAOTOU);
                        file = biao_places[random(sizeof(biao_places))];
                        ob->move(file);
                        dest = environment(ob);            
                        message("vision",
                        ob->name() + "Ѻ���ڳ����˹�����\n",
                        dest, ({ob}));
                        region = explode(file, "/")[1];
                        ling->set("job/name", ob->query("nickname"));
                        return "ȥ���̵ĵ����ǻ�������" + 
                        ob->query("nickname") + 
                        "���ڳ�������" + 
                        //region_names[region] +
                        to_chinese("region") +
                        dest->query("short") + "��";
                } else {
                        ob = obj[random(sizeof(obj))];
                        dest = environment(ob);
                        biaoju = (string)ob->query("nickname");

                        if( !dest || !biaoju ) {
                                destruct(ob);
                                command("shake");
                                return "��Ъ�Űɣ����û��Ҫ���İ���";
                        }

                        file = base_name(dest);
                        if( strsrch(file, "/d/") != 0
                        || !mapp(dest->query("exits")) ) {
                                destruct(ob);
                                command("shake");
                                return "��Ъ�Űɣ����û��Ҫ���İ���";
                        }

                        command("nod");
                        region = explode(file, "/")[1];
                        ling->set("job/name", biaoju);
                        return "ȥ���̵ĵ����ǻ�������" + biaoju + 
                        "���ڳ�������" + 
                        //region_names[region] + 
                        to_chinese("region") +
                        dest->query("short") + "��";
                }
                break;

        case "ʾ��":
                obj = filter_array(children(BANGZHONG), (: clonep :));
                if( sizeof(obj) ) {
                obj = filter_array(obj, "is_victim", this_object(), myfam);
                if( sizeof(obj) ) {
                        command("nod");
                        ob = obj[random(sizeof(obj))];
                        ob_bang = (string)ob->query("title");
                        me->set_temp("bangs/victim", ob_bang);
                        ling->set("job/name", ob_bang);
                        return "���" + ob_bang + "���������ǹ���ȥ����ȥɱһ��ʾʾ����";
                }
                }
                break;

        case "����":
                command("nod");

                job = info_guest[random(sizeof(info_guest))];
                region = explode(job["file"], "/")[1];

                ob = new(CAILI);
                ob->set("job", job);
                ob->set("owner", me);
                ling->set("job/title", job["title"]);
                ling->set("job/area", job["area"]);
                ob->set("long",
"����һ��" + myfam + "�����͸�" + "��" + job["title"] + "��" + "�Ĳ���\n");
                ob->move(me);
                message_vision("$N��һ" + ob->query("unit") + ob->name() + "����$n��\n", this_object(), me);
                return "�����ݲ����͸�" + job["area"] + "��" + "��" + job["title"] + "��" + "��";
                break;

        case "����":
                command("nod");
                files = get_dir(BANGGOOD);
                if( !sizeof(files) ) {
                         command("shake");
                         return "��Ъ�Űɣ����û��Ҫ���İ���";
                }
                file = BANGGOOD + files[random(sizeof(files))];
                ob = new(file);
                ob->move(me);
                message_vision("$N��һ" + ob->query("unit") + ob->name() + "����$n��\n", this_object(), me);
                ling->set("job/name", ob->name());
                ling->set("job/good", ob->query("id"));
                ling->set("job/prices", info_business[ob->name()]);
                return "�����" + ob->query("unit") + ob->name() + "��ȥ�����ü�Ǯ��";
                break;

        case "���":
                command("nod");
                ling->set("job/name", "���");
                return "��ȥ�챦�󵱲�ɡ�";
                break;
        }

        command("shake");
        return "��Ъ�Űɣ����û��Ҫ���İ���";
}

void do_start(object me, object ob)
{
        ob->move(environment());
        destruct(this_object());
}

int accept_object(object who, object ob)
{
        object obj;
        int bonus, record;
        string name, chname = "";
        mapping job;

        if( who->query("party/party_name") != query("party/party_name") ) 
                return notify_fail(name() + "��ŭ�����󵨣���ı�����ܹܣ�����\n");

        if( !(obj = present("bang ling", who)) )
                return notify_fail(name() + "��ŭ����û���õĶ������������㶪����\n");

        if( !mapp(job = obj->query("job")) )
                return notify_fail(name() + "��ŭ����û���õĶ��������Լ��İ��񶼼ǲ�ס����\n");

        switch(job["type"]) {
        case "Ѱ":
                name = ob->name();
                for(int i = 0; i < strlen(name); i++)
                        if(name[i] > 160 && name[i] < 255) 
                                chname += name[i..i];
                if( chname != job["name"] )
                        return notify_fail(name() + "��ŭ����û���õĶ��������Լ��İ��񶼼ǲ�ס����\n");
                bonus = job["bonus"] * job["max"] / ((int)who->query("combat_exp") + 1000);
                record = bonus / 2 + random(bonus);
                log_file("test/BangJob", sprintf("%s��%sʱ�ҵ�%s��%s�����\n", who->query("name"), ctime(time()), chname, chinese_number(record)));
                bonus = job["score"];
                break;

        case "����":
                if( base_name(ob) != BIAOHUO )
                        return notify_fail(name() + "��ŭ����û���õĶ�������һ֦�ڶ��㲻����\n");
                if( ob->query("my_killer") != who->query("id") )
                        return notify_fail(name() + "��ŭ��������������ľ������ã������������������㣡\n");
                break;  
        }

        command("nod");
        obj->delete("job");

        who->add("combat_exp", record);
        who->add("shen", -bonus);
        obj->add("score", bonus);

        remove_call_out("store");
        call_out("store", 1, ob);
        return 1;
}

void store(object ob)
{
 //       ob->move("/d/shenlong/cangku");
  destruct(ob);
}

private is_victim(object ob, string arg)
{
        string fam;

        if( !stringp(fam = ob->query("title")) ) return 0;
        if( fam == arg ) return 0;

        return 1;
}

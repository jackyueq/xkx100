// ���������ڵ�����������WIZLELVELȨ�����ϵ���ʦ������
// ����������֮ǰ����������shop resetָ���ʼ�����е���״̬
// �������������ַ�ʽ����ʦ�ֹ�������ϵͳ�Զ�����

// ������������ֹ���������������ʦ��������״�����Զ����̽��ӹ�������
// ������ʦ�뿪������
// ������ʦ����
// ������ʦ�������κ��������������涨ʱ��
// ������ʦ����
// ������ʦ���Ի�������

// ���������б�NPC����ĸ��²��ᵼ���������̵��жϣ�����update,dest & clone

#include <ansi.h>
#include <getconfig.h>

inherit NPC;
inherit F_SAVE;

#define WIZLEVEL 3 //  �ܹ�������ִ����������ʦ�ȼ�
#define DISTANCE 8 //  �����м����ʱ�䣨�룩
#define DELAY 30   //  ������������ʦû�н����κζ����ĵȴ�ʱ�䣨�룩
                   //  �������ʱ�䣬�Զ����̽ӹ�����

string query_save_file();
int do_start(string arg);		// ������������ʹ��arg������ʾ�����ֹ�����
int do_auction(string arg);		// ָ�������ĵ�ǰ����
int begin_auction();			// �ȴ���Ҿ�Ͷ���ػ�����
int stop_auction();			// ������ǰ���̵�����
int do_jupai(string arg);		// ��Ҿ�Ͷ�ж�
int go_jupai();				// ��Ҿ�Ͷ���ػ�����
int do_qiao();				// ��ʦ�����Լ����
int do_auctionlist();			// ��ѯ���������б�
int do_ban(string arg);		        // ȡ��|�ָ� ��������ʸ�
int finish_auction(string arg);		// ��������
void heart_beat();			// �����ߣ��ֹ������ػ�����
object check_operator();		// ���������ʦ״̬����
int do_autoauction();			// ���ֹ�����תΪ�Զ�����
int last_time = 0;	                // ���һ���ֹ�������ʱ��
object operator;		        // ��������¼����������

void create()
{
        seteuid(getuid());
        restore();

        set_name("˾ͽ��", ({ "situ heng", "heng", "situ" }));
        set("title", "���ְ�ǰ�����������̻��ܹ�");
        set("channel_id","˾ͽ��");
        set("gender", "����");
        set("age", 45);
        set("combat_exp", 800000);
        set("shen", -1);
        set("attitude", "friendly");

        set("max_qi", 3000);
        set("max_jing", 2500);
        set("neili", 3500);
        set("max_neili", 3500);
        
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("sword", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);

        set("apply/attack", 100);
        set("apply/defense", 100);

        setup();

        if (! clonep(this_object()))
        {
                move("/d/city/zxlpath");
                message_vision(CYN "\n$N" CYN "���˹��������˿���Χ����Ц������\n" NOR, this_object());
                set("startroom", "/d/city/zxlpath");
        }

        carry_object(CLOTH_DIR"cloth")->wear();
        set_heart_beat(1);
}


void init()
{
        ::init();
        if (wiz_level(this_player()) >= WIZLEVEL)
        {
                add_action("do_auction", ({ "auction", "paimai" }));
                add_action("do_start","start");
                add_action("do_qiao", "qiao");
                add_action("do_ban", "ban");
                add_action("finish_auction", "finish");
                add_action("do_autoauction", ({ "auto", "autopaimai"}));
        }

        add_action("do_auctionlist", ({ "list", "paimailist" }));
        add_action("do_jupai", "jupai");
}

//  �����ĵ�
string query_save_file()
{
        return "/data/shop/shop";
}

int do_start(string arg)
{
        object ob,me;
        int i;
        string *shop_list,msg;
        mapping *all_shop;
        mapping begin_shop;
        mapping end_shop;

        me = this_player();
        ob = this_object();

        if (ob->query("auction_start") && ! ob->query("auction_end"))
                return notify_fail("�������������У��޷����¿�ʼ��\n");

        if (! SHOP_D->is_inited())
        {
                msg ="������δȫ����ʼ�������ڽ�������֮ǰ�����е��̳�ʼ����\n";
                write(msg);
                return 1;
        } else
        {
                shop_list = ({});
                begin_shop = ([]);
                end_shop = ([]);
                
                remove_call_out("do_auction");
                remove_call_out("begin_auction");
                remove_call_out("stop_auction");
                remove_call_out("go_jupai");
                remove_call_out("finish_auction");
                
                all_shop = SHOP_D->query_shop();
                msg = HIC "�ɹ���ʼ���������򣬴����������б� \n" NOR;
                msg += HIC "--------------------------------------\n" NOR;
                for (i = 0;i < sizeof(all_shop);i++)
                {
                	if (all_shop[i]["name"]==SHOP_D->query_top()) 
                	{
                		command("say "+all_shop[i]["id"]+all_shop[i]["name"]+"�ٻ������ܻ�ӭ�������ţ��������һ���¡�");
                		continue;
                	}
                        shop_list += ({ all_shop[i]["id"] });
                        begin_shop[all_shop[i]["id"]] = all_shop[i]["price"];
                        msg += sprintf(HIY "%-20s" HIW "\t%d���ƽ�\n" NOR,all_shop[i]["id"],all_shop[i]["price"]);
                }
                msg += HIC "--------------------------------------\n" NOR;
                msg += WHT "�ܹ���" + chinese_number(sizeof(all_shop)) + "�ҵ��̡�\n" NOR;

                ob->delete("owner");
                ob->delete("shop_list");
                ob->delete("begin_shop");
                ob->delete("end_shop");
                ob->delete("auction_end");
                ob->delete("now_auction");
                ob->delete("temp_owner");
                ob->delete("wait_jupai");
                ob->delete("on_jupai");
                ob->delete("can_finish");

                ob->set("auction_start", 1);
                ob->set("shop_list", shop_list);
                ob->set("begin_shop", begin_shop);
                ob->set("end_shop", end_shop);
                if (arg)
                {
                        CHANNEL_D->do_channel(ob, "sys", "��������ϵͳ��" + me->name(1) + "�ɹ�����������ģʽ���Զ���");

                        // ��������Ϊ�Զ�����
                        ob->set("operator", "situ heng");

                        msg += HIR "��ѡ����ͨ��" HIW "�Զ�����" HIR "�ķ�ʽ�������������̡�\n\n" NOR;
                        write(msg);

                        message_vision(CYN"$N"CYN"������Ц������Ȼ��λ��׼�����ˣ���ô���ǾͿ�ʼ�����ɡ�\n" NOR, ob);
                        operator = ob;
                        ob->save();
                        call_out("do_auction", 0, "automatic");
                }
		else
                {
                        CHANNEL_D->do_channel(ob, "sys", "��������ϵͳ��" + me->name(1) + "�ɹ�����������ģʽ���˹���");

		        // ��������Ϊ�ֹ�����
                        ob->set("operator", me->query("id"));

                        msg += HIR "��ѡ����ͨ��" HIW "�˹�����" HIR "�ķ�ʽ�������������̡�\n\n" NOR;
                        msg += WHT "������ָ��Ϊ(" HIY "auction <����ID>" NOR + WHT ")��\n" NOR;
                        msg += WHT "��������(" HIY "auto" NOR + WHT ")ָ��������������ת���Զ����С�\n" NOR;
                        write(msg);

                        message_vision(CYN"$N"CYN"���˲�������Ц������ε�������$n" CYN "�������֡�\n" NOR, ob, me);
                        message_vision(HIC"$N"HIC"��Ц�����������еĴ���֣�ؽ���$n" HIC "��\n" NOR, ob, me);
                        operator = me;

                        // ��¼�ôβ���ʱ��
                        last_time = time();

                        // �����ֹ������ػ�����
                        set_heart_beat(1);
                        ob->save();
                }
        }
        return 1;
}

int do_auction(string arg)
{
        object ob;
        string *shop_list, now_shop, msg, *shop_key;
        mapping begin_shop;
        int i, now_price;

        if (! query("auction_start") || query("auction_end"))
                return notify_fail("���ڲ�û���ڽ���������\n");

        if (! arg)
                return notify_fail("ָ���ʽ��auction <����ID>\n");

        if (query("now_shop"))
                return notify_fail("�������ڽ���" + query("now_shop") +"���̵������������ż���\n");

        ob = this_object();

        if (ob != operator && this_player() != operator)
                return notify_fail("���ڵ�����������" + operator->name(1) +"���ֽ����С�\n");

        remove_call_out("do_auction");
        remove_call_out("finish_auction");
        remove_call_out("begin_auction");

        shop_list = query("shop_list");
        begin_shop = query("begin_shop");

	//  ���Զ���
        if (ob != operator)
        {
		// �Ѿ�ȫ�����������
                if (sizeof(shop_list) < 1)
                {
                        set("can_finish", 1);
                        save();
                        return notify_fail(WHT "���е��̶��Ѿ����������ˣ������ڿ��Խ���(" HIY "finish" NOR + WHT ")�����ˡ�\n" NOR);
                }

		//  �ύ�Ĳ�������������ʾ���д����������б�
                if (! begin_shop[arg])
                {
                        msg = HIR"�Բ��������ύ�ĵ��̲������ڡ�\n\n" NOR;
                        msg += WHT"�ȴ������ĵ����б� \n" NOR;
                        msg += HIC"--------------------------------------\n"NOR;
                        shop_key = keys(begin_shop);

                        for (i = 0; i < sizeof(shop_key); i++)
                                msg += sprintf(HIW "%-20s" HIY "\t%d���ƽ�\n"NOR, shop_key[i], begin_shop[shop_key[i]]);

                        msg += HIC"--------------------------------------\n"NOR;
                        msg += WHT "�ܹ���" + chinese_number(sizeof(shop_key)) + "�ҵ��̿���������\n\n";
                        write(msg);
                        return 1;
                }
		// ��ǰ��������
                now_shop = arg;
        } else	// �Զ�����
        {
                // ȫ�����̶��Ѿ��������
                if (sizeof(shop_list) < 1)
                {
                        ob->set("can_finish", 1);
                        ob->save();
                        // ���ý�����������
                        call_out("finish_auction", 0, "automatic");
                        return 1;
                }
		// ��ǰ��������
                now_shop = shop_list[random(sizeof(shop_list))];
        }

	// �Ӵ��ĵ�����ɾ����ǰ��������
        shop_list -= ({ now_shop });
        now_price = query("begin_shop/" + now_shop);
        ob->set("wait_jupai", 1);
        ob->set("shop_list", shop_list);
        ob->delete("begin_shop/" + now_shop);
        ob->set("now_shop", now_shop);
        ob->set("now_price", now_price);
        ob->save();

        CHANNEL_D->do_channel(ob, "sys", "���ڿ�ʼ����" + now_shop + "���̡�");

//        message_vision(
        shout(HIY "�����̡�" WHT+ operator->name()+ WHT "�����������ڿ�ʼ������" HIC + now_shop + HIC "����" WHT "���׼�Ϊ" + chinese_number(now_price) + "���ƽ�����������ơ�\n" NOR);
      //  , operator);

        // �Զ�����
        if (ob == operator)
                call_out("begin_auction", DISTANCE);
        else
                // ��¼�ôβ�����ʱ��
                last_time = time();

        return 1;
}

int begin_auction()
{
        string now_shop;
        int now_price,m;
        object ob;

        ob = this_object();

        m = ob->query("wait_jupai");

	// �Ѿ����˿�ʼ����
        if (! m)
                return 1;

        remove_call_out("begin_auction");
        remove_call_out("stop_auction");

        now_shop = query("now_shop");
        now_price = query("now_price");

        m += 1;
        ob->set("wait_jupai",m);
        ob->save();

        switch (random(3))
        {
        case 0:

                message_vision(CYN "\n$N" CYN "���ŵ������ڿ�ʼ����" HIC + now_shop + NOR + CYN "���̡�����Ϊ" YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Ρ�\n" NOR, operator);
                break;

        case 1:
                message_vision(CYN "\n$N" CYN "���˿���Χ������������" YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Σ�" YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Ρ�����" + HIC + now_shop + NOR + CYN "���̡�\n" NOR, operator);
                break;

        default:
                message_vision(CYN "\n$N" CYN "�ɿ�������������������Ϊ" YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Σ�����" + HIC + now_shop + NOR + CYN "���̣�����" "�ߴ��١�\n" NOR, operator);
                break;
        }

        switch (random(4))
        {
        case 0:

                message_vision(CYN"$N" CYN "������һ�����ܣ�����˵�����������߾���(" HIY "jupai" NOR + CYN ")��\n" NOR, operator);
                break;

        case 1:
                message_vision(CYN"$N" CYN "������üͷ��˵��������Ը�⹺��ô���뼴ʱ����(" HIY "jupai" NOR + CYN ")��\n" NOR, operator);
                break;

        case 2:
                message_vision(CYN"$N" CYN "΢Ц������λ���Ǻ���ô������Ը�����(" HIY "jupai" NOR + CYN ")����ô��\n" NOR, operator);
                break;

        default:
                message_vision(CYN "$N" CYN "������ɤ�ӣ�����˵������������" "���У����λ����(" HIY "jupai" NOR + CYN ")ʾ" "�⡣\n" NOR, operator);
                break;
        }

	// �Զ�����
        if (operator == ob)
        {
                if (! (m >= 3)) call_out("begin_auction",DISTANCE);
                else call_out("stop_auction",DISTANCE);
	// �ֹ����� 
        } else
                // ��¼���һ�β�����ʱ��
                last_time = time();
}

int stop_auction()
{
        string now_shop, temp_owner, *owner, *shop_list, msg, *shop_key;
        mapping begin_shop, end_shop, *shop_record, record;
        object ob, the_owner;
        int i, now_price;
        
        remove_call_out("stop_auction");
        remove_call_out("go_jupai");
        remove_call_out("begin_auction");
        remove_call_out("finish_auction");
        remove_call_out("do_auction");

        msg = "";
        ob = this_object();
        owner = query("owner");
        temp_owner = query("temp_owner");
        shop_list = query("shop_list");
        begin_shop = query("begin_shop");
        end_shop = query("end_shop");
        now_shop = query("now_shop");
        now_price = query("now_price");

        if (! mapp(end_shop) || sizeof(end_shop) < 1)
                end_shop = ([]);

        if (! arrayp(owner) || sizeof(end_shop) < 1)
                owner = ({});

        if (query("wait_jupai"))
        {
                message_vision(BEEP + HIY "\n$N" HIY "�������е�Сľ�������һ�ã�ֻ���á�������һ�����졣\n" NOR, operator);
                message_vision(HIY "$N" HIY "����������������" HIC + now_shop + HIY "���̵�����Ȩ���������ˡ�\n" NOR, operator);

                end_shop[now_shop] = 0;
                ob->delete("wait_jupai");
                ob->delete("now_shop");
                ob->set("end_shop", end_shop);
                ob->save();

                // �Զ�����
                if (operator == ob)
                {
                	// ���е�����������
                        if (sizeof(shop_list) < 1)
                        {
                                set("can_finish", 1);
                                save();
                                call_out("finish_auction", 0, "automatic");
                                return 1;
                        }
                        call_out("do_auction", 1, "automatic");
                } else
                {
                        // ���е�����������
                        if (sizeof(shop_list) < 1)
                        {
                                set("can_finish", 1);
                                save();
                                tell_object(operator, WHT"���е��̶��Ѿ����������������ڿ��Խ���(" HIY "finish" NOR + WHT ")������\n"NOR);
                                return 1;
                        }

                        msg += HIC "�ȴ������ĵ����б� \n" NOR;
                        msg += HIC "��" HIY "����������������������������" HIC "��\n" NOR;
                        shop_key = keys(begin_shop);

                        for (i = 0; i < sizeof(shop_key); i++)
                                msg += sprintf(CYN "%-20s" WHT "\t%d���ƽ�\n" NOR, shop_key[i], begin_shop[shop_key[i]]);
                        msg += HIC "��" HIY "����������������������������" HIC "��\n" NOR;
                        msg += HIC "�ܹ���" HIY + chinese_number(sizeof(shop_key)) + HIC "�ҵ��̿���������\n\n";

                        tell_object(operator, msg);
                        // ��¼�ôβ���ʱ��
                        last_time = time();
                }
                return 1;
        } else            
        {
                //  ���ȼ�鵱ǰ��Ͷ���̵�����Ƿ����ߣ������Ƿ���Ͷ���ϻ�
                //  Ǯׯȡ���˴���������������쳣����õ������¹�����ĵ�
                //  �����飬����ȡ������ҵ������ʸ�

                the_owner = find_player(temp_owner);
                if (! objectp(the_owner) ||
			(int)the_owner->query("balance")<(int)(now_price*10000))
                {
                	// ȡ������ҵ������ʸ�
                        do_ban(temp_owner + " 1");
                        begin_shop[now_shop] = 2000;
                        ob->set("begin_shop", begin_shop);

                        message_vision(HIY "$N" HIY "��Цһ��������Ȼ�Ҹ����棿" + temp_owner + HIY "�����쳣��ȡ�������ʸ�" "��\n\n" NOR, operator);

                        CHANNEL_D->do_channel(ob, "sys", "����" + temp_owner + "�����쳣��ȡ������ҵ������ʸ�" + now_shop + "�������¹���������б�");
                } else
                {
                        // ��¼������ʷ����
                        record = ([]);
                        shop_record = query(now_shop);

                        if (! sizeof(shop_record)) shop_record = ({});

                        record["time"] = time();
                        record["id"] = the_owner->query("id");
                        record["name"] = the_owner->name(1);
                        record["pms"] = operator->name(1);
                        record["value"] = now_price;
                        shop_record += ({ record });
                        ob->set(now_shop, shop_record);

                        the_owner->add("balance", - now_price * 10000);
                        the_owner->save();
                        owner += ({ temp_owner });
                        ob->set("owner", owner);
                        end_shop[now_shop] = now_price;
                        ob->set("end_shop", end_shop);
                        SHOP_D->change_owner(operator, now_shop, temp_owner);

                        message_vision(BEEP + HIY "\n$N" HIY "�������е�Сľ�������һ�ã�ֻ���á�������һ�����졣\n" NOR, operator);
                        message_vision(HIY "$N" HIY "�������������ɽ�����ϲ" + the_owner->name() + HIY "��" NOR + YEL + chinese_number(now_price) +"���ƽ�" HIY "�ļ۸�����" HIC + now_shop + HIY "���̵�����Ȩ��\n" NOR, operator);
                        shout(HIY "�����̡�" NOR + WHT + operator->name() + WHT "[" + operator->query("id") + WHT "]����ϲ" + the_owner->name() + NOR + WHT "�����" + now_shop + NOR + WHT "���̵�����Ȩ��\n" NOR);
                        CHANNEL_D->do_channel(ob, "sys", temp_owner + "�����" + now_shop + "���̵�����Ȩ�����ճ���" + chinese_number(now_price) + "���ƽ�");
                        tell_object(the_owner, HIC + BLINK "\n��ϲ����" + chinese_number(now_price) + "���ƽ�ļ۸��õ��̵�����Ȩ��\n" NOR);
                }        
                ob->delete("on_jupai");
                ob->delete("now_shop");
                ob->delete("now_price");
                ob->delete("temp_owner");
                ob->save();

		// �Զ�����
                if (operator == ob)
                {
                        // ���е�����������
                        if (sizeof(shop_list) < 1)
                        {
                                set("can_finish", 1);
                                save();    
                                call_out("finish_auction", 0, "automatic");
                        } else call_out("do_auction", 1, "automatic");
                } else
                {
                        // ���е�����������
                        if (sizeof(shop_list) < 1)
                        {
                                set("can_finish", 1);
                                save();
                                tell_object(operator, WHT"���е��̶��Ѿ����������ˣ������ڿ��Խ���(" HIY "finish" NOR + WHT ")�����ˡ�\n"NOR);
                                return 1;
                        }

                        msg += WHT"�ȴ������ĵ����б� \n" NOR;
                        msg += HIC"--------------------------------------\n"NOR;
                        shop_key = keys(begin_shop);

                        for (i = 0; i < sizeof(shop_key); i++)
                                msg += sprintf(HIW "%-20s" HIY "\t%d���ƽ�\n" NOR, shop_key[i], begin_shop[shop_key[i]]);

                        msg += HIC"--------------------------------------\n"NOR;
                        msg += WHT"�ܹ���" + chinese_number(sizeof(shop_key)) + "�ҵ��̿���������\n\n";

                        tell_object(operator,msg);
 
                        // ��¼�ôβ���ʱ��
                        last_time = time();
                }
                return 1;
        }
}

int do_jupai(string arg)
{
        object ob, buyer;
        string now_shop, temp_owner;
        int money, now_price;

        ob = this_object();
        buyer = this_player();

	if (buyer->query("score") < 3000)
                return notify_fail("��Ľ�������̫�ͣ��Ժ������ɡ�\n");
        if (! query("auction_start"))
                return notify_fail("����������û�п�ʼ�������ļ���\n");

	//  �ֹ����������ִ����ʦ�Ƿ��ڣ�������������תΪ�Զ�
        if (operator != ob) operator = check_operator();
        if (! query("now_shop"))
               return notify_fail(operator->name(1) +"��û������Ҫ�����ļҵ��̣��㼱��ɶ��\n");

        if (arrayp(query("owner")) &&
		member_array(buyer->query("id"), query("owner")) != -1)
                return notify_fail("���Ѿ������˵��̣��ͱ�̫�ĺ��ˡ�\n");

        if (arrayp(query("ban")) &&
		member_array(buyer->query("id"), query("ban")) != -1)
                return notify_fail("���Ѿ���ȡ���������ʸ���ʵ��ɡ�\n");

        if (buyer->query("id") == query("temp_owner"))
                return notify_fail("��ǰ�ļ۸�������������Ͷ�ġ�\n");

        now_shop = query("now_shop");
        now_price = query("now_price");
        temp_owner = buyer->query("id");

        if (! arg) money = 30;
        else
                if (! (sscanf(arg, "%d", money) == 1) ||
			money < 30 || money > 1000)
                        return notify_fail("�����Ӽ۶�����(30-1000)�ƽ�\n");

        if ((int)buyer->query("balance") < (money + now_price) * 10000)
                return notify_fail("���ʻ����Ǯ������" + chinese_number(money+now_price) + "���ƽ�\n");

        remove_call_out("begin_auction");
        remove_call_out("go_jupai");
        remove_call_out("stop_auction");

        now_price += money;
        
        ob->set("temp_owner", temp_owner);
        ob->set("on_jupai", 1);
        ob->set("now_price", now_price);
        ob->delete("wait_jupai");
        ob->save();

        tell_object(buyer, HIC "����˾����е����ӣ�ʾ��Ӽ�" + chinese_number(money) + "���ƽ�\n" NOR);

        message_vision(HIW "\n$N" HIW "��Ц�����ã�����" + buyer->name() + HIW "����" NOR + YEL + chinese_number(now_price) + "���ƽ�" HIW "����λ��������ۡ�\n" NOR, operator);

        switch (random(3))
        {
        case 0:

                message_vision(CYN"$N" CYN "������һ�����ܣ�����˵���������߿ɼ�������(" HIY "jupai" NOR + CYN ")�Ϲ���\n" NOR, operator);
                break;

        case 1:
                message_vision(CYN"$N" CYN "΢Ц��������Ը����ƴ��ô���������߼�������(" HIY "jupai" NOR + CYN ")���ۡ�\n" NOR, operator);
                break;

        default:
                message_vision(CYN"$N" CYN "������ɤ�ӣ����ŵ����������ڽ��У����λ��������(" HIY "jupai" NOR + CYN ")ʾ�⡣\n" NOR, operator);
                break;
        }

	// �Զ�����
        if (operator == ob)
                call_out("go_jupai", DISTANCE);
        else
                // ��¼��ǰ����ʱ��
                last_time = time();

        return 1;
}

int go_jupai()
{
        object ob;
        int m, now_price;
        string now_shop, temp_owner;
        
        remove_call_out("go_jupai");
        remove_call_out("stop_auction");

        ob = this_object();
        m = query("on_jupai");
        now_shop = query("now_shop");
        now_price = query("now_price");
        temp_owner = query("temp_owner");

        m += 1;
        ob->set("on_jupai", m);
        ob->save();

        switch (random(3))
        {
        case 0:
                message_vision(CYN "\n$N" CYN "���ŵ���������������" HIC + now_shop + NOR + CYN "���̡�����Ϊ" + YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Ρ�\n" NOR, operator);
                break;

        case 1:
                message_vision(CYN "\n$N" CYN "�������ܴ����������ڱ���Ϊ" YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Σ�����" + HIC + now_shop + NOR + CYN "���̡�\n" NOR, operator);
                break;

        default:
                message_vision(CYN "\n$N" CYN "�ɿ�������������������Ϊ" YEL + chinese_number(now_price) + "���ƽ�" CYN "��" + chinese_number(m) + "�Σ�����" + HIC + now_shop + NOR + CYN "���̣�����" "�ߴ��١�\n" NOR, operator);
                break;
        }

        switch (random(3))
        {
        case 0:

                message_vision(CYN"$N" CYN "������һ�����ܣ�����˵���������߿ɼ�������(" HIY "jupai" NOR + CYN ")�Ϲ���\n" NOR, operator);
                break;

        case 1:
                message_vision(CYN"$N" CYN "΢Ц��������Ը����ƴ��ô���������߼�������(" HIY "jupai" NOR + CYN ")���ۡ�\n" NOR, operator);
                break;

        default:
                message_vision(CYN"$N" CYN "������ɤ�ӣ����ŵ����������ڽ��У����λ��������(" HIY "jupai" NOR + CYN ")ʾ�⡣\n" NOR, operator);
                break;
        }

	// �Զ�����
        if (operator == ob)
        {
                if (! (m >= 3))
                        call_out("go_jupai", DISTANCE);
                else
                        call_out("stop_auction", DISTANCE);
	// �ֹ����� 
        } else
                // ��¼���һ�β�����ʱ��
                last_time = time();

        return 1;
}

int do_qiao()
{
        object ob,me;
        int m;

        ob = this_object();
        me = this_player();

        if (! query("auction_start"))
                return notify_fail(WHT "�����������̻�û��������������(" HIY "start" NOR + WHT ")ָ���������������̡�\n" NOR);

        if (operator != me)
                return notify_fail("����������������"+ operator->name(1) + "�����У����Ϳ����ɡ�\n");

        remove_call_out("do_auction");
        remove_call_out("begin_auction");
        remove_call_out("stop_auction");
        remove_call_out("go_jupai");

        // �Ѿ��������ĵ��̣��ȴ�������
        if (m = query("wait_jupai"))
        {
                if (! (m >= 3)) call_out("begin_auction", 0);
                else call_out("stop_auction", 0);
        }
	else
	        if (m = query("on_jupai"))
		{
			if (! (m >= 3)) call_out("go_jupai", 0);
			else call_out("stop_auction", 0);
		} else return notify_fail("��׼���������������ĸ����̣�\n");

        return 1;
}

int do_auctionlist()
{
        int i,now_price;
        object me;
        string msg, now_shop, *shop_list, *shop_key;
        mapping begin_shop, end_shop;

        msg = "";
        me = this_player();
        now_shop = query("now_shop");
        now_price = query("now_price");
        begin_shop = query("begin_shop");
        end_shop = query("end_shop");

        if (query("auction_start"))
                msg += HIC "������������֮�С�\n" NOR;
        else
                msg += HIC "���ڲ�û�����������̡�\n" NOR;

        msg += HIC "--------------------------------------\n" NOR;

        if (now_shop)
        {
                msg += sprintf(HIY "��ǰ�������̣�\n" HIW "%-20s"
                               HIY "\t%d���ƽ�\n" NOR,
                               now_shop, now_price);
                msg += HIC "--------------------------------------\n" NOR;
        }

        if (mapp(begin_shop) && sizeof(begin_shop) > 0)
        {
                msg += WHT "�����������б� \n" NOR;
                shop_key = keys(begin_shop);

                for (i = 0; i < sizeof(shop_key); i++)
                        msg += sprintf(HIW "%-20s" HIY "\t%d���ƽ�\n" NOR, shop_key[i], begin_shop[shop_key[i]]);

                msg += HIC "--------------------------------------\n" NOR;
        }

        if (mapp(end_shop) && sizeof(end_shop) > 0)
        {
                msg += HIR "�ѱ����������б� \n" NOR;
                shop_key = keys(end_shop);

                for (i = 0; i < sizeof(shop_key); i++)
                        msg += sprintf(HIW "%-20s" HIY "\t%d���ƽ�\n" NOR, shop_key[i], end_shop[shop_key[i]]);

                msg += HIC "--------------------------------------\n" NOR;
        }

        tell_object(me,msg);
        return 1;
}

int do_ban(string arg)
{
        int i, m;
        string *ban, msg;
        ban = query("ban");

        if (! ban || sizeof(ban) < 1)
                ban = ({ });

        if (! arg)
        {
                if (sizeof(ban) < 1)
                        return notify_fail("����û����Ҹ�ȡ�������ʸ�\n");

                msg = HIC "ȡ�������ʸ������б�\n" NOR;
                msg += HIC "------------------------------------\n" NOR;

                for (i = 0; i < sizeof(ban); i++)
                        msg += HIY + ban[i] + "\n" + NOR;

                msg += HIC "------------------------------------\n" NOR;
                msg += WHT "�ܹ�" + sizeof(ban) + "λ��Ҹ�ȡ�������ʸ�\n" NOR;

                msg += HIC "\nָ���ʽ��ban [id] [1|0]\n"
                       "���в���idȱʡ��ʾ��ѯ���������Ϊ1����"
                       "ȱʡ��ʾ��ӣ�Ϊ0��ʾɾ����\n" NOR;

                tell_object(this_player(), msg);
                return 1;
        }

        if (sscanf(arg, "%s %d", arg, m) != 2)
                m = 1;

        if (m)
        {
                if (member_array(arg, ban) == -1)
                {
                        ban += ({ arg });
                        set("ban", ban);
                }
        } else
        {
                if (member_array(arg, ban) != -1)
                {
                        ban -= ({ arg });
                        set("ban", ban);
                }
        }
        save();
        return 1;
}

int finish_auction(string arg)
{
        object me,ob;
        ob = this_object();

        if (!arg || arg != "automatic")
        {
                me = this_player();

                if (! query("auction_start"))
                        return notify_fail("�������̲�û��������\n");

                if (! query("can_finish"))
                        return notify_fail("�����������ڽ����У��޷���ֹ��\n");

                if (operator != me)
                        return notify_fail("������"+ operator->name(1) + "���ֵ������������ͱ�����ˡ�\n");
        }

        remove_call_out("finish_auction");

        ob->delete("can_finish");
        ob->delete("shop_list");
        ob->delete("begin_shop");
        ob->delete("auction_start");
        ob->set("auction_end", 1);
        ob->delete("wait_jupai");
        ob->delete("on_jupai");
        ob->delete("now_shop");
        ob->delete("now_price");
        ob->delete("temp_owner");
        ob->delete("owner");
        ob->save();

        message_vision(CYN"\n$N" CYN "����ĵ��˵�ͷ���������ε�������Բ��������\n" NOR, operator);

        CHANNEL_D->do_channel(ob, "sys", "����������ϡ�" + operator->name(1) + "�������������̣�");

        if (operator == ob)
        {
                SHOP_D->open_all(operator);
                message_vision(CYN"$N" CYN "Ц�������������ĳ�����ȫ�����ţ����æȥ�ɡ�\n" NOR, operator);
        } else
                tell_object(operator, WHT "�����ڿ�����(" HIY "shop open" NOR + WHT ")ָ��ŵ��̡�\n" NOR);

        shout(HIY "�����̡�" NOR + WHT + operator->name() + WHT "[" + operator->query("id") + WHT "]��������ᵽ�˽�������λ����(" HIY "shop" NOR + WHT ")�鿴���ҵ������顣\n" NOR);

        return 1;
}

// ������ -- ���ڼ�������������̵���ʦ�Ƿ�״̬����
// ���״̬����������תΪ�Զ�����ģʽ�����ҹر�������
void heart_beat()
{
        int m;
        object ob,obj;
        string the_operator;

        ob = this_object();

        if (! query("auction_start") || operator == this_object())
        {
                set_heart_beat(0);
                return;
        }

        the_operator = query("operator");

        if (! the_operator)
        {
                set_heart_beat(0);
                return;
        }

        if (! operator
           || ! (obj = find_player(the_operator))
           || ! living(obj)
           || environment(obj) != environment(ob)
           || (time() - last_time) > 30)
        {
                set_heart_beat(0);
                operator = this_object();

                command("say ������š��������е�������Ҫæ��������"
                        "����������ɡ�");

                CHANNEL_D->do_channel(ob, "sys", "����" + the_operator + "״̬�쳣��������������ת���Զ�ģʽ��");
                set("operator", "situ heng");
                save();

                if (m = query("wait_jupai"))
                {
                        if (!(m >= 3))
                               call_out("begin_auction",DISTANCE);
                        else
                               call_out("stop_auction",DISTANCE);
                } else
                if (m = query("on_jupai"))
                {
                        if (!(m >= 3))
                                call_out("go_jupai",DISTANCE);
                        else
                                call_out("stop_auction",DISTANCE);
                } else
                        call_out("do_auction", 0, "automatic");
        }

        return;
}

object check_operator()
{
        object obj;
        string the_operator;

        the_operator = query("operator");

        if (! (obj = find_player(the_operator))
           || ! living(obj)
           || environment(obj) != environment())
        {
                set("operator", "situ heng");
                save();
                return this_object();
        }
        return obj;
}

int do_autoauction()
{
        object ob,me;
        int m;

        ob = this_object();
        me = this_player();

        if (! query("auction_start"))
                return notify_fail("�������̲�û����������ô�Զ�����\n");

        if (operator != me)
                return notify_fail("���������������������֡�\n");

        operator = this_object();
        set_heart_beat(0);

        message_vision(CYN "$N" CYN "���ֽ�$n" CYN "��������˵�������е������£��������������ɡ�\n" NOR, me, ob);
        message_vision(CYN "$N" CYN "��æ��$n" CYN "��Ц���������˼�æ���ģ�����ͽ����Ұɡ�\n" NOR, ob, me);

        CHANNEL_D->do_channel(ob, "sys", me->query("id") + "����������ת���Զ�ģʽ��");
        set("operator", "situ heng");
        save();

        if (m = query("wait_jupai"))
        {
                if (! (m >= 3))
                        call_out("begin_auction", DISTANCE);
                else
                        call_out("stop_auction", DISTANCE);
        } else
        if (m = query("on_jupai"))
        {
                if (! (m >= 3))
                        call_out("go_jupai", DISTANCE);
                else
                        call_out("stop_auction", DISTANCE);
        } else
                call_out("do_auction", 0, "automatic");

        return 1;
}
